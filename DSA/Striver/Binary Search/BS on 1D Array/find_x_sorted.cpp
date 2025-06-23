#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &arr, int target)
{
  int low = 0, high = arr.size() - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] == target)
      return mid; // Found
    else if (arr[mid] < target)
      low = mid + 1; // Go right
    else
      high = mid - 1; // Go left
  }

  return -1; // Target not found
}

int main()
{
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 9;

  int ans = search(nums, target);
  cout << ans;
}
