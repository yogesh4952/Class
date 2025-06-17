#include <bits/stdc++.h>
using namespace std;

int subArray(vector<int> &arr, int target)
{
  // Using prefix sum approach

  int size = arr.size();
  vector<int> ps(size);
  ps[0] = arr[0];

  // Calculate prefix sum
  for (int i = 1; i < size; i++)
  {
    ps[i] = ps[i - 1] + arr[i];
  }

  int count = 0;
  unordered_map<int, int> hash; // PS,FREQUENCY
  for (int j = 0; j < size; j++)
  {

    if (ps[j] == target)
      count++;

    int value = ps[j] - target;
    if (hash.find(value) != hash.end())
    {
      count = count + hash[value];
    }

    if (hash.find(ps[j]) == hash.end())
    {
      hash[ps[j]] = 0;
    }
    hash[ps[j]]++;
  }

  return count;
}
int main()
{
  vector<int> arr = {9, 0, 1, 3, 6};
  int ans = subArray(arr, 4);

  cout << ans << endl;
  return 0;
}