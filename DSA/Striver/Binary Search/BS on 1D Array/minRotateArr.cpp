#include <bits/stdc++.h>
using namespace std;

int minValue(vector<int> &arr)
{
  int ans = INT_MAX;
  int low = 0;
  int high = arr.size() - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    // For already sorted case

    if (arr[low] <= arr[high])
    {
      ans = min(ans, arr[low]);
      break;
    }
    // Left sorted

    if (arr[low] <= arr[mid])
    {

      ans = min(ans, arr[low]);
      low = mid + 1;
    }
    else
    {
      ans = min(arr[mid], ans);
      high = mid - 1;
    }

    // Right Sorted
  }

  return ans;
}
int main()
{

  vector<int> arr = {3, 4, 100, 2, 3};
  cout << minValue(arr);
}