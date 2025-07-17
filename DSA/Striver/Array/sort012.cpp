#include <bits/stdc++.h>
using namespace std;
// Optimal Approach with DNF Algorithm

void DNF(vector<int> &arr)
{
  int low = 0;
  int mid = 0;
  int high = arr.size() - 1;

  while (mid <= high)
  {
    if (arr[mid] == 0)
    {
      swap(arr[mid], arr[low]);
      low++;
      mid++;
    }

    else if (arr[mid] == 1)
    {
      mid++;
    }

    else

    {
      swap(arr[mid], arr[high]);
      high--;
    }
  }
}

int main()
{
  vector<int> arr = {2, 0, 2, 1, 1, 0};

  DNF(arr);
  for (auto i : arr)
  {
    cout << i << " ";
  }

  // int cnt1 = 0;
  // int cnt2 = 0;
  // int cnt3 = 0;
  // for (int i = 0; i < arr.size(); i++)
  // {
  //   if (arr[i] == 0)
  //   {
  //     cnt1++;
  //   }
  //   else if (arr[i] == 1)
  //   {
  //     cnt2++;
  //   }
  //   else
  //   {
  //     cnt3++;
  //   }
  // }

  // int index = 0;

  // for (int i = 0; i < cnt1; i++)
  // {
  //   arr[index] = 0;
  //   index++;
  // }
  // for (int i = 0; i < cnt2; i++)
  // {
  //   arr[index] = 1;
  //   index++;
  // }

  // for (int i = 0; i < cnt3; i++)
  // {
  //   arr[index] = 2;
  //   index++;
  // }

  // for (int i = 0; i < arr.size(); i++)
  // {
  //   cout << arr[i] << " ";
  // }
}
