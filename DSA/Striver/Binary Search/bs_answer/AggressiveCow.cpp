#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &arr, int dist, int cows)
{
  int cntCows = 1;
  int last = arr[0];
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] - last >= dist)
    {
      cntCows++;
      last = arr[i];
    }

    if (cntCows >= cows)
      return true;
  }
  return false;
}

int maxiAggressive(vector<int> &arr, int cows)
{
  sort(arr.begin(), arr.end());
  int low = 1;
  int high = arr[arr.size() - 1] - arr[0];

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (canWePlace(arr, mid, cows))
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return high;
}

int main()
{
}