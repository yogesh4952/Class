#include <bits/stdc++.h>
using namespace std;

vector<int> alternate(vector<int> &arr)
{

  // Optimized version
  int size = arr.size();
  vector<int> ans(size, 0);

  int posIndex = 0;
  int negIndex = 1;
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] < 0)
    {

      ans[negIndex] = arr[i];
      negIndex += 2;
    }
    else
    {
      ans[posIndex] = arr[i];
      posIndex += 2;
    }
  }

  return ans;
}
int main()
{
  vector<int> arr{1, 2, 3, -1, -2, -3};
  vector<int> ans = alternate(arr);
  cout << "[";
  for (int i = 0; i < arr.size(); i++)
  {
    cout << ans[i] << ",";
  }
  cout << "]";
  return 0;
}