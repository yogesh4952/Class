//! This problem is same as the book allocation problem

#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr, int noOfPages, int number)
{
  // TODO: write validation function

  int count = 1;

  int sum = 0;

  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] > noOfPages)
      return false;

    //! Condition for second painter
    if (arr[i] + sum > noOfPages)
    {

      count++;
      sum = arr[i];
    }

    //! Normal addition
    else
    {
      sum += arr[i];
    }
  }
  return count <= number;
}

int maxOfMin(vector<int> &arr, int number)
{
  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);

  //* Return if the number of painters are greater

  if (arr.size() < number)
    return -1;

  int ans = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (isValid(arr, mid, number))
    {
      ans = mid;
      high = mid - 1;
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
  cout << maxOfMin(arr, 2);
  return 0;
}