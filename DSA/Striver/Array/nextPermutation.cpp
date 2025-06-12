#include <bits/stdc++.h>
#include <myutils/next_permutation.h>
using namespace std;

// void nextPermutation(vector<int> &arr)
// {
//   int n = arr.size();
//   int index = -1;

//   // Step 1: Find the dip index
//   for (int i = n - 2; i >= 0; i--)
//   {
//     if (arr[i] < arr[i + 1])
//     {
//       index = i;
//       break;
//     }
//   }

//   if (index == -1)
//   {
//     // Entire array is in descending order, so return lowest (ascending)
//     reverse(arr.begin(), arr.end());
//     return;
//   }

//   // Step 2: Find the next greater element to the right of index
//   for (int i = n - 1; i > index; i--)
//   {
//     if (arr[i] > arr[index])
//     {
//       swap(arr[i], arr[index]);
//       break;
//     }
//   }

//   // Step 3: Reverse the suffix starting at index + 1
//   reverse(arr.begin() + index + 1, arr.end());
// }

int main()
{
  vector<int> arr = {2, 1, 5, 4, 3, 0, 0, 0, 0};

  nextPermutation(arr);

  for (int x : arr)
  {
    cout << x << " ";
  }

  return 0;
}
