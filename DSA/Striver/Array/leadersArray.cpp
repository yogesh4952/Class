#include <bits/stdc++.h>
using namespace std;
void leaders(vector<int> &arr)
{
  int max = INT_MIN;

  for (int i = arr.size() - 1; i >= 0; i--)
  {
    if (arr[i] > max)
    {
      cout << arr[i] << " ";
      max = arr[i];
    }
  }
}
int main()
{

  vector<int> arr = {10, 22, 12, 3, 0, 6};

  leaders(arr);

  return 0;
}
