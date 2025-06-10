#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<int> arr = {0, 0, 1, 1, 1, 0, 0, 1, 0, 2, 0, 1, 0, 2, 0, 2};

  int cnt1 = 0;
  int cnt2 = 0;
  int cnt3 = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] == 0)
    {
      cnt1++;
    }
    else if (arr[i] == 1)
    {
      cnt2++;
    }
    else
    {
      cnt3++;
    }
  }

  int index = 0;

  for (int i = 0; i < cnt1; i++)
  {
    arr[index] = 0;
    index++;
  }
  for (int i = 0; i < cnt2; i++)
  {
    arr[index] = 1;
    index++;
  }

  for (int i = 0; i < cnt3; i++)
  {
    arr[index] = 2;
    index++;
  }

  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
}
