#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{

  int n = arr.size();

  int maxLen = -1;

  unordered_map<int, int> mpp;

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
    if (sum == 0)
    {
      maxLen = i + 1;
    }
    else if (mpp.find(sum) != mpp.end())
    {
      maxLen = max(maxLen, (i - mpp[sum]));
    }
    else
    {
      mpp[sum] = i;
    }
  }

  /*
for (int i = 0; i < n; i++)
{
  int sum = 0;
  for (int j = i; j < n; j++)
  {
    sum = sum + arr[j];
    if (sum == 0)
    {
      maxLen = max(maxLen, (j - i) + 1);
    }
  }
}

*/
  return maxLen;
}

int main()
{
  vector<int> arr = {-42, 12, 20, 15, 31, -4, 0, 15};
  cout << solve(arr) << endl;
  return 0;
}