#include <bits/stdc++.h>
using namespace std;

vector<double> combine(vector<double> &arr1, vector<double> &arr2)
{
  vector<double> arr;

  int left = 0;
  int right = 0;

  int n1 = arr1.size();
  int n2 = arr2.size();

  // Merge both arrays while both have elements
  while (left < n1 && right < n2)
  {
    if (arr1[left] <= arr2[right])
    {
      arr.push_back(arr1[left]);
      left++;
    }
    else
    {
      arr.push_back(arr2[right]);
      right++;
    }
  }

  // Add remaining elements from arr1 (if any)
  while (left < n1)
  {
    arr.push_back(arr1[left]);
    left++;
  }

  // Add remaining elements from arr2 (if any)
  while (right < n2)
  {
    arr.push_back(arr2[right]);
    right++;
  }

  return arr;
}

double median(vector<double> &arr1, vector<double> &arr2)
{
  vector<double> arr = combine(arr1, arr2);
  int n = arr.size();

  // If odd number of elements
  if (n % 2 == 1)
  {
    return arr[n / 2];
  }
  // If even number of elements
  else
  {
    return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
  }
}
int main()
{
  vector<double> arr1 = {1, 3, 5};
  vector<double> arr2 = {2, 4, 6};
  double ans = median(arr1, arr2);
  cout << ans << endl;
  return 0;
}