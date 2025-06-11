// problem: Return an element which have occured highesh and occurence must will be n/2

#include <bits/stdc++.h>
using namespace std;

// Using two loops the T.C Will be o(n*n)
int majorityElement(vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)

  {
    int count = 0;
    for (int j = 0; j < arr.size(); j++)
    {
      if (arr[i] == arr[j])
      {
        count++;
      }
    }

    if (count > arr.size() / 2)
    {
      return arr[i];
    }
  }

  return -1;
}

int main()
{
  vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
  int ans = majorityElement(arr);
  cout << ans << endl;
}