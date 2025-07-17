#include <bits/stdc++.h>
using namespace std;

long long generateSum(vector<int> &arr, int mid)
{
  long long total = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    total += (arr[i] + mid - 1) / mid;
  }
  return total;
}

int smallestDivisor(vector<int> &arr, int thresshold)
{
  int low = 1;
  int high = INT_MIN;
  for (int i = 0; i < arr.size(); i++)
  {
    high = max(high, arr[i]);
  }
  int ans = -1;

  while (low <= high)
  {

    int mid = (low + high) / 2;

    if (generateSum(arr, mid) <= thresshold)
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
  vector<int> arr = {1, 2, 5, 9};
  cout << smallestDivisor(arr, 6);
}