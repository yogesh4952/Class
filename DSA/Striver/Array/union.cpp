#include <bits/stdc++.h>
using namespace std;

void Union(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    set<int> st;

    for (int i = 0; i < n1; i++)
    {
        st.insert(arr1[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        st.insert(arr2[i]);
    }

    vector<int> temp;
    for (auto it : st)
    {
        temp.push_back(it);
        cout << it << " ";
    }
    // return temp;
}

int main()
{
    vector<int> arr1 = {1, 1, 2, 3, 4, 5, 5, 5, 6};
    vector<int> arr2 = {0, 1, 2, 3, 3, 3, 3};

    Union(arr1, arr2);

    return 0;
}