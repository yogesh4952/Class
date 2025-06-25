#include <bits/stdc++.h>
using namespace std;

int countRotation(vector<int> &arr)
{
  int low = 0;
  int high = arr.size() - 1;

  int ans = -1;
  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[low] <= arr[high])
    {
      return 0;
    }

    if (arr[low] <= arr[mid])
    {
      ans = (ans, high);
      low = mid + 1;
    }
    else
    {
      ans = max(ans, mid - 1);
      high = mid - 1;
    }
  }

  return ans;
}
int main()
{
  vector<int> arr = {3, 4, 1, 2, 2};
  cout << countRotation(arr);
}