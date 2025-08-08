#include <stdio.h>
#include <stdlib.h> // for abs()

void FCFS(int arr[], int size, int head)
{
  int seek_count = 0;
  int cur_track, distance;

  for (int i = 0; i < size; i++)
  {
    cur_track = arr[i];
    distance = abs(head - cur_track); // abs for int
    seek_count += distance;
    head = cur_track;
  }

  printf("Total number of seek operations: %d\n", seek_count);
  printf("Seek Sequence is:\n");

  for (int i = 0; i < size; i++)
  {
    printf("%d\t", arr[i]);
  }
}

int main()
{
  int arr[] = {176, 79, 34, 60, 92, 11, 41, 114};
  int size = sizeof(arr) / sizeof(arr[0]);
  int head = 50;

  FCFS(arr, size, head);

  return 0;
}
