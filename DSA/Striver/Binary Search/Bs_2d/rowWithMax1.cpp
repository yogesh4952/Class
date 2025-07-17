#include <bits/stdc++.h>
using namespace std;

// Brute force method to find the row with the maximum number of 1s
int maximum1(int arr[5][5])
{
  int maxCnt = -1;
  int index = -1;

  for (int i = 0; i < 5; i++)
  {
    int cnt = 0;
    for (int j = 0; j < 5; j++)
    {
      if (arr[i][j] == 1)
      {
        cnt++;
      }
    }

    if (cnt > maxCnt)
    {
      maxCnt = cnt;
      index = i;
    }
  }
  return index + 1;
}

int main()
{
  int arr[5][5] = {
      {0, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {0, 0, 0, 1, 1},
      {0, 0, 0, 0, 0},
      {0, 1, 1, 1, 1}};

  int result = maximum1(arr);
  cout << "Row with maximum number of 1s: " << result << endl;

  return 0;
}
