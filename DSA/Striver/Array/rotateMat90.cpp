#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &arr)
{
  int n = arr.size();
  int m = arr[0].size();

  // Here we're solving this problem using optmial approach

  /*
    1) Transpose matrix
    2) Reverse the row
  */

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      arr[i][j] = arr[j][i];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  vector<vector<int>> arr = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};

  rotate(arr);
  return 0;
}
