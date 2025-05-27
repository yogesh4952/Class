#include <bits/stdc++.h>
using namespace std;

vector<int> Intersection(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> visitedArray(n2, 0);

    vector<int> intersectionArray;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j] && visitedArray[j] == 0)
            {
                intersectionArray.push_back(arr1[i]);
                visitedArray[j] = 1;
                break;
            }

            if (arr2[j] > arr1[i])
            {
                break;
            }
        }
    }

    return intersectionArray;
}

int main()
{
    vector<int> arr1 = {1, 1, 1, 2, 3, 4, 4, 5, 6};
    vector<int> arr2 = {1, 2, 4, 4, 5, 6, 78};

    vector<int> ans = Intersection(arr1, arr2);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}