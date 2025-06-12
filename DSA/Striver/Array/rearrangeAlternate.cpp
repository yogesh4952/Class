#include <bits/stdc++.h>
using namespace std;

void alternate(vector<int> &arr)
{

  vector<int> positive;
  vector<int> negative;

  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] < 0)
    {
      negative.push_back(arr[i]);
    }
    else
    {
      positive.push_back(arr[i]);
    }
  }
  for (int i = 0; i < arr.size() / 2; i++)
  {
    arr[i * 2] = positive[i];
    arr[i * 2 + 1] = negative[i];
  }
}
int main()
{
  vector<int> arr{1, 2, 3, -1, -2, -3};
  alternate(arr);
  cout << "[";
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << ",";
  }
  cout << "]";
  return 0;
}