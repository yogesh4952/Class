#include <bits/stdc++.h>
using namespace std;

vector<int> majorityII(vector<int> &arr)
{
  vector<int> ans;

  unordered_map<int, int> temp;

  for (int i = 0; i < arr.size(); i++)
  {
    if (temp.find(arr[i]) == temp.end())
    {
      temp[arr[i]] = 0;
    }
    temp[arr[i]]++;
  }

  for (auto it : temp)
  {
    if (it.second > (arr.size() / 3))
    {
      ans.push_back(it.first);
    }
  }
  return ans;
}
int main()
{
  vector<int> arr = {1, 2};
  vector<int> ans = majorityII(arr);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}