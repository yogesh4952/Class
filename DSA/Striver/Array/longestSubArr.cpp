#include <bits/stdc++.h>
using namespace std;

// Function to calculate size  longest subarray

int lengthSubArr(vector<int> &arr, int sum)
{
  int len = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    int maxSum = 0;
    for (int j = i; j < arr.size(); j++)
    {
      maxSum += arr[j];
      if (maxSum > sum)
        break;

      len = max(len, j - i + 1);
    }
  }
  return len;
}

int main()
{

  vector<int> arr = {1, 1, 1, 2, 3, 2, 1, 5, 56, 3, 2, 1, 6, 7, 1};
  int ans = lengthSubArr(arr, 5);
  cout << ans << endl;

  return 0;
}