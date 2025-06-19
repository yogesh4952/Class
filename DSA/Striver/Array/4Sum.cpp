#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int target)
{
  set<vector<int>> st;

  if (arr.size() < 4)
    return {};

  vector<vector<int>> ans;

  sort(arr.begin(), arr.end());

  for (int i = 0; i < arr.size(); i++)

  {
    for (int j = i + 1; j < arr.size(); j++)
    {
      int left = j + 1;
      int right = arr.size() - 1;
      while (left < right)
      {
        int sum = static_cast<long long>(arr[left]) + static_cast<long long>(arr[right]) + static_cast<long long>(arr[i]) + static_cast<long long>(arr[j]);
        if (sum == target)
        {
          vector<int> value = {arr[i], arr[j], arr[left], arr[right]};

          sort(value.begin(), value.end());

          st.insert(value);
          left++;
          right--;
        }
        else if (sum > target)
        {
          right--;
        }
        else
        {
          left++;
        }
      }
    }
  }

  for (auto &vc : st)
  {
    ans.push_back(vc);
  }

  return ans;
}

int main()
{
  vector<int> arr = {
      1000000000, 1000000000, 1000000000, 1000000000};
  int target = -294967296;
  vector<vector<int>> ans = fourSum(arr, target);

  for (auto it : ans)
  {
    cout << "[";
    for (int element : it)
    {
      cout << element << " ";
    }
    cout << "]";
  }

  return 0;
}