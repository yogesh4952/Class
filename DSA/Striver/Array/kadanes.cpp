#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int> &arr)
{
  int maxi = arr[0];
  int sum = arr[0];

  for (int i = 1; i < arr.size(); i++)
  {
    sum = max(arr[i], sum + arr[i]);
    maxi = max(sum, maxi);
  }
  return maxi;
}
int main()
{
  vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  vector<int> arr1 = {5, 4, -1, 7, 8};
  int ans = maxSum(arr1);
  cout << ans;
}