#include <bits/stdc++.h>
using namespace std;

void rotate(const vector<vector<int>> &arr)
{
  int n = arr.size();
  int m = arr[0].size();
  vector<vector<int>> ans(m, vector<int>(n));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      ans[j][n - 1 - i] = arr[i][j];
    }
  }

  for (auto &row : ans)
  {
    for (int val : row)
      cout << val << ' ';
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
