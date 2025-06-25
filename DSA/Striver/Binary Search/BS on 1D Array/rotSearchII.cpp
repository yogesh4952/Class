#include <bits/stdc++.h>
using namespace std;

int index(vector<int> &arr, int target)
{
  int low = 0;
  int high = arr.size() - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] == target)
      return mid;

    if (arr[mid] == arr[low] && arr[mid] == arr[high])
    {
      low = low + 1;
      high = high - 1;

      continue;
    }

    if (arr[low] <= arr[mid])
    {
      if (arr[low] <= target && target <= arr[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    else
    {
      if (arr[mid] <= target && target <= arr[high])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }

  return {-1};
}
int main()
{

  vector<int> arr = {3, 1, 2, 3, 3, 3, 4};
  int ans = index(arr, 3);
  cout << ans;
}