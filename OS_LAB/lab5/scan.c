#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define DISK_SIZE 200

void sortArray(int arr[], int n)
{
  int i, j, temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void SCAN(int arr[], int head, char direction[])
{
  int seek_count = 0;
  int distance, cur_track;
  int left[SIZE + 1], right[SIZE + 1];
  int left_size = 0, right_size = 0;
  int seek_sequence[SIZE + 2];
  int seek_index = 0;

  // Append end values depending on direction
  if (direction[0] == 'l') // "left"
    left[left_size++] = 0;
  else if (direction[0] == 'r') // "right"
    right[right_size++] = DISK_SIZE - 1;

  // Divide requests into left and right
  for (int i = 0; i < SIZE; i++)
  {
    if (arr[i] < head)
      left[left_size++] = arr[i];
    else if (arr[i] > head)
      right[right_size++] = arr[i];
  }

  // Sort both sides
  sortArray(left, left_size);
  sortArray(right, right_size);

  int run = 2;
  while (run--)
  {
    if (direction[0] == 'l')
    {
      for (int i = left_size - 1; i >= 0; i--)
      {
        cur_track = left[i];
        seek_sequence[seek_index++] = cur_track;
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
      }
      direction[0] = 'r';
    }
    else if (direction[0] == 'r')
    {
      for (int i = 0; i < right_size; i++)
      {
        cur_track = right[i];
        seek_sequence[seek_index++] = cur_track;
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
      }
      direction[0] = 'l';
    }
  }

  printf("Total number of seek operations = %d\n", seek_count);
  printf("Seek Sequence is:\n");
  for (int i = 0; i < seek_index; i++)
  {
    printf("%d\t", seek_sequence[i]);
  }
}

int main()
{
  int arr[SIZE] = {176, 79, 34, 60, 92, 11, 41, 114};
  int head = 50;
  char direction[] = "left";

  SCAN(arr, head, direction);
  return 0;
}
