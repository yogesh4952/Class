// problem: Return an element which have occured highesh and occurence must will be n/2

#include <bits/stdc++.h>
using namespace std;

// Using two loops the T.C Will be o(n*n)
/*
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

*/

// Solving the same problem using better approach

/*
int majorityElement(vector<int> &arr)
{

map<int, int> mpp;
for (int i = 0; i < arr.size(); i++)
{
  mpp[arr[i]]++;
}

for (auto it : mpp)
{
  if (it.second > arr.size() / 2)
  {
    return it.first;
  }
}

return -1;
}
*/

// Using moore's voting algorithm
int majorityElement(vector<int> &arr)
{
  int cnt = 0;
  int el;

  for (int i = 0; i < arr.size(); i++)
  {
    if (cnt == 0)
    {
      cnt = 1;
      el = arr[i];
    }
    else if (arr[i] == el)
    {
      cnt++;
    }
    else
    {
      cnt--;
    }
  }

  if (cnt == 0)
  {
    return -1;
  }
  cnt = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] == el)
    {
      cnt++;
    }
  }

  if (cnt > arr.size() / 2)
  {
    return el;
  }
  else
  {
    return -1;
  }
}

int main()
{
  vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
  int ans = majorityElement(arr);
  map<int, int> mpp;

  cout << ans << endl;
}