#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    vector<int> temp;
    for (int i = arr.size() - k; i < arr.size(); i++)
    {
        temp.push_back(arr[i]);
    }

    for (int i = arr.size() - 1; i >= k; i--
)
    {
        arr[i] = arr[i - k];
    }

    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}