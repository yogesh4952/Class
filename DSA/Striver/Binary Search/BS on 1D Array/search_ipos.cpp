#include <bits/stdc++.h>
using namespace std;

int getIndex(vector<int> &arr, int x)
{
  int ans = arr.size();

  int low = 0;
  int high = arr.size() - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] >= x)
    {
      ans = mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return ans;
}

int main()
{
  vector<int> arr = {1, 3, 5, 6};
  cout << getIndex(arr, 4);
}