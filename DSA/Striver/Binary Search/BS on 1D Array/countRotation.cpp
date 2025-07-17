#include <bits/stdc++.h>
using namespace std;

int countRotation(vector<int> &arr)
{
  int low = 0;
  int high = arr.size() - 1;
  int index = -1;

  int ans = INT_MAX;
  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[low] <= arr[high])
    {
      if (arr[low] < ans)
      {
        ans = arr[low];
        index = low;
      }
      break;
    }

    if (arr[low] <= arr[mid])
    {

      if (arr[low] < ans)
      {
        ans = arr[low];
        index = low;
      }
      high = mid - 1;
    }
    else
    {

      if (arr[mid] < ans)
      {
        ans = arr[mid];
        index = mid;
      }
      low = mid + 1;
    }
  }

  return index;
}
int main()
{

  vector<int> arr = {3, 4, 0, 1, 2};
  cout << countRotation(arr);
}