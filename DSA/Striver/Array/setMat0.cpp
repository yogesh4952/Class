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
  vector<vector<int>> arr = {{1, 1, 1},
                             {1, 0, 1},
                             {1, 1, 1}};

  setZeroes(arr);
  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = 0; j < arr[0].size(); j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}