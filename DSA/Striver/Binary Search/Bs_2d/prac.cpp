#include <bits/stdc++.h>
using namespace std;

#define size 5
int occurrenceIndex(int arr[size])
{
  int low = 0;
  int high = size - 1;

  int ans = -1;
  while (low <= high)
  {
    int mid = (high + low) / 2;

    if (arr[mid] == 1)
    {
      high--;
    }
    else
    {
      ans = mid;
      low++;
    }
  }
  return ans;
}

int max1(int arr[5][5])
{
  int max_cnt = -1;
  int index = -1;
  for (int i = 0; i < 5; i++)
  {
    int cnt_ones = 4 - occurrenceIndex(arr[i]);
    if (cnt_ones > max_cnt)
    {
      max_cnt = cnt_ones;
      index = i;
    }
  }

  return index;
}
int main()
{
  int arr[5][5] = {
      {0, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {0, 1, 1, 1, 1},
      {0, 0, 1, 1, 1},
      {0, 0, 0, 0, 0}};

  int ans = max1(arr);
  cout << ans;
  return 0;
}