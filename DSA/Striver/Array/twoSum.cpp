#include <bits/stdc++.h>
using namespace std;

vector<int> sum(vector<int> &arr, int target)
{

  map<int, int> mpp;
  for (int i = 0; i < arr.size(); i++)

  {
    int required = target - arr[i];

    if (mpp.find(required) != mpp.end())
    {
      return {mpp[required], i};
    }

    mpp[arr[i]] = i;
  }

  return {-1, -1};
}

int main()
{
  vector<int> nums = {15, 7, 11, 15, 1, 2, 3, 4, 5};
  int target = 5;
  vector<int> ans = sum(nums, target);

  cout << ans[0] << ' ' << ans[1] << endl;
}
