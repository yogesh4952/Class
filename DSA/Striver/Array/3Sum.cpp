#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(vector<int> arr)
{
  vector<vector<int>> ans;
  if (arr.size() < 3)
    return ans;

  sort(arr.begin(), arr.end()); // Step 1: Sort array

  set<vector<int>> temp; // To store unique triplets

  for (int i = 0; i < arr.size(); i++)
  {
    int left = i + 1; // Start just after the current element
    int right = arr.size() - 1;
    int constant = arr[i];

    while (left < right)
    {
      int sum = arr[left] + arr[right] + constant;
      if (sum == 0)
      {
        vector<int> triplet = {arr[left], arr[right], constant};
        sort(triplet.begin(), triplet.end());
        temp.insert(triplet);
        left++;
        right--;
      }
      else if (sum < 0)
      {
        left++;
      }
      else
      {
        right--;
      }
    }
  }

  for (auto &vec : temp)
  {
    ans.push_back(vec);
  }

  return ans;
}

int main()
{
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ans = triplet(nums);

  for (auto &row : ans)
  {
    cout << "[ ";
    for (int val : row)
    {
      cout << val << " ";
    }
    cout << "]\n";
  }

  return 0;
}
