#include <bits/stdc++.h>
using namespace std;

int findPeak(vector<int> &arr)
{

  int n = arr.size();

  if (arr[0] > arr[1])
    return arr[0];

  if (arr[n - 1] > arr[n - 2])
    return arr[n - 1];

  int low = 1;
  int high = n - 2;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
      return arr[mid];

    // Elimination

    if (arr[mid] < arr[mid + 1])
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return -1;
}

int main()
{

  vector<int> arr = {1, 2, 3, 1};
  cout << findPeak(arr) << endl;
  return 0;
}