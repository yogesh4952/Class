#include <bits/stdc++.h>
using namespace std;

int finFloorSqrt(int n)
{
  int low = 1;
  int high = n;

  int ans = INT_MAX;
  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (mid * mid > n)
    {
      high = mid - 1;
    }
    else
    {
      ans = mid;
      low = mid + 1;
    }
  }
  return ans;
}
int main()
{
  cout << finFloorSqrt(100);
  return 0;
}