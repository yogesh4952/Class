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
    if (i > 0 && arr[i] == arr[i - 1])
      continue;
    for (int j = i + 1; j < arr.size(); j++)
    {

      if (j > i + 1 && arr[j] == arr[j - 1])
        continue;
      int left = j + 1;
      int right = arr.size() - 1;
      while (left < right)
      {
        long long sum = static_cast<long long>(arr[left]) + static_cast<long long>(arr[right]) + static_cast<long long>(arr[i]) + static_cast<long long>(arr[j]);
        if (sum == target)
        {

          ans.push_back({arr[i], arr[j], arr[left], arr[right]});

          while (left < right && arr[left] == arr[left + 1])
            left++;
          while (left < right && arr[right] == arr[right - 1])
            right--;

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