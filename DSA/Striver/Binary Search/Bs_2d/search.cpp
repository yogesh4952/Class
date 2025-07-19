#include <bits/stdc++.h>
using namespace std;

int findRows(vector<int> arr, int target)
{
  int low = 0;
  int high = arr.size() - 1;
  while (low <= high)
  {
    int mid = low - (high + low) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] < target)
    {
      low++;
    }
    else
    {
      high--;
    }
  }
  return -1;
}

int search(vector<vector<int>> arr, int target)
{
  int ans = -1;

  for (int i = 0; i < arr.size(); i++)
  {
    ans = findRows(arr[i], target);
  }
  return ans;
}
int main()
{
  return 0;
}