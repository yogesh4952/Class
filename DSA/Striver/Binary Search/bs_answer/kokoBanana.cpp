#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &arr)
{
  int maxi = arr[0];
  for (int i = 1; i < arr.size(); i++)
  {
    if (arr[i] > maxi)
    {
      maxi = arr[i];
    }
  }

  return maxi;
}

int totalHour(vector<int> &arr, int x)
{
  int total = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    total = total + ceil((double)arr[i] / x);
  }
  return total;
}

int koko(vector<int> arr, int x)
{

  int high = findMax(arr);

  int low = 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (totalHour(arr, mid) <= x)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return low;
}

int main()
{
  vector<int> arr = {3, 6, 7, 11};
  cout << koko(arr, 8);
}