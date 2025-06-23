#include <bits/stdc++.h>
using namespace std;

int getIndex(vector<int> &arr, int x)
{
  int low = 0;
  int high = arr.size() - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[low] <= arr[mid])
    {
      if (arr[low] <= x && x <= arr[mid])
      {
        low = mid + 1;
      }
    }
    else
    {
    }
  }
}