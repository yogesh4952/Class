#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &arr)
{

  int n = arr.size();
  int m = arr[0].size();

  bool firstColHasZero = false;

  for (int i = 0; i < n; i++)
  {
    if (arr[0][0] == 0)
      firstColHasZero = true;

    for (int j = 1; j < m; j++)
    {
      if (arr[i][j] == 0)
      {
        arr[i][0] = 0; // mark column
        arr[0][j] = 0; // Mark colunn
      }
    }
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      if (arr[i][0] == 0 || arr[0][j] == 0)
      {
        arr[i][j] = 0;
      }
    }
  }

  if (arr[0][0] == 0)
  {
    for (int j = 0; j < m; j++)
    {
      arr[0][j] = 0;
    }
  }

  if (firstColHasZero)

  {
    for (int j = 0; j < n; j++)
    {
      arr[j][0] = 0;
    }
  }
}
int main()
{
  int mat[3][3] = {{1, 1, 1},
                   {1, 0, 1},
                   {1, 1, 1}};

  int col[3] = {0};
  int row[3] = {0};

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (mat[i][j] == 0)
      {
        row[i] = 1;
        col[j] = 1;
      }
    }
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (row[i] == 1 || col[j] == 1)
      {
        mat[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << mat[i][j] << " ";
    }

    cout << endl;
  }
  return 0;
}