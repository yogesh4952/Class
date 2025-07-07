// Brute force approach

#include <bits/stdc++.h>
using namespace std;
int bookAllocation(vector<int> &arr, int students)
{
  if (arr.size() < students)
    return -1;

  int ans = INT_MAX;

  for (int i = 0; i < arr.size(); i++)
  {
    int sum = 0;
    for (int j = i; j < arr.size(); j++)
    {
      sum = sum + arr[j];
      ans = min(ans, sum);
    }
  }

  return ans;
}

int main()
{
  vector<int> arr = {2, 1, 3, 4};
  cout << bookAllocation(arr, 2);
  return 0;
}