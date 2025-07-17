#include <bits/stdc++.h>
using namespace std;

// Lower bound

int lower_bound(vector<int> &arr, int target)
{
  int low = 0;
  int high = arr.size() - 1;
  int ans = -1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] >= target)
    {

      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  return ans;
}
int main()
{
  vector<int> arr = {3, 5, 8, 15, 19};
  int x = lower_bound(arr, 9);

  cout << x << endl;
}