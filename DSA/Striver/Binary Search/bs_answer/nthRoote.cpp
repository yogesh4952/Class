#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m)
{
  int low = 1;
  int high = m;

  int ans = -1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int power = 1;

    for (int i = 0; i < n; i++)
    {
      power *= mid;
      if (power > m)
        break;
    }

    if (power == m)
      return mid;
    else if (power > m)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return -1;
}
int main()
{
  cout << NthRoot(3, 9);
  return 0;
}