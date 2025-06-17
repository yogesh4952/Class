#include <bits/stdc++.h>
using namespace std;

vector<int> generateRows(int row)

{
  long long ans = 1;
  vector<int> ansRow;
  ansRow.push_back(ans);

  for (int col = 1; col < row; col++)
  {
    ans = ans * (row - col);
    ans = ans / col;
    ansRow.push_back(ans);
  }
  return ansRow;
}

vector<vector<int>> pascalTriangle(int numRows)
{
  vector<vector<int>> ans;

  for (int i = 1; i <= numRows; i++)
  {
    ans.push_back(generateRows(i));
  }

  return ans;
}
int main()
{
  vector<vector<int>> ans = pascalTriangle(5);
  for (auto &it : ans)
  {
    for (int a : it)
    {
      cout << a << " ";
    }
    cout << endl;
  }
}