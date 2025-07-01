#include <bits/stdc++.h>
using namespace std;

int generateBoque(vector<int> &arr, int mid, int adjacent)
{

  int count = 0;
  int total = 0;

  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] <= mid)
    {
      count++;
    }
    else
    {
      total = total + (count / adjacent);
      count = 0;
    }
  }
  total += (count / adjacent);
  return total;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
  int mini = INT_MAX;
  int maxi = INT_MIN;
  int ans = -1;
  for (int i = 0; i < bloomDay.size(); i++)
  {
    mini = min(mini, bloomDay[i]);
    maxi = max(maxi, bloomDay[i]);
  }
  while (mini <= maxi)
  {
    int mid = (mini + maxi) / 2;

    if (generateBoque(bloomDay, mid, k) < m)
    {
      mini = mid + 1;
    }
    else
    {
      ans = mid;
      maxi = mid - 1;
    }
  }
  return ans;
}

int main()
{
  vector<int> arr = {1, 10, 3, 10, 2};
  cout << minDays(arr, 3, 1);
}