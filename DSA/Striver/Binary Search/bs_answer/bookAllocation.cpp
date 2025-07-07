// Brute force approach

#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr, int maxPages, int students)
{
  int count = 1;
  int sum = 0;
  for (int i = 0; i < arr.size(); i++)
  {

    if (arr[i] > maxPages)
      return false;

    if (sum + arr[i] > maxPages)
    {
      count++;
      sum = arr[i];
    }
    else
    {
      sum += arr[i];
    }
  }

  return count <= students;
}

int bookAllocation(vector<int> &arr, int students)
{
  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);

  if (arr.size() < students)
    return -1;

  int ans = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (isValid(arr, mid, students))
    {
      high = mid - 1;
      ans = mid;
    }
    else
    {
      low = mid + 1;
    }
  }

  return ans;
}

int main()
{
  vector<int> arr = {10, 20, 30, 40};
  cout << bookAllocation(arr, 2);
}
