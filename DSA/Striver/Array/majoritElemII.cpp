#include <bits/stdc++.h>
using namespace std;

vector<int> majorityII(vector<int> &arr)
{
  vector<int> ans;

  int count1 = 0;
  int count2 = 0;
  int element1 = INT_MIN;
  int element2 = INT_MIN;

  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    if (element1 == arr[i])
    {
      count1++;
    }
    else if (element2 == arr[i])
    {
      count2++;
    }

    else if (count1 == 0)
    {
      count1 = 1;
      element1 = arr[i];
    }

    else if (count2 == 0)
    {
      count2 = 1;
      element2 = arr[i];
    }
    else
    {
      count1--;
      count2--;
    }
  };
  // Verification

  count1 = count2 = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == element1)
      count1++;
    else if (arr[i] == element2)
      count2;
  }

  if (count1 > n / 3)
    ans.push_back(element1);

  if (count2 > n / 3)
    ans.push_back(element2);
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