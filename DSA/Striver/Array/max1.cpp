#include <bits/stdc++.h>
using namespace std;

int maxConss(vector<int> &a)
{
    int cnt = 0;
    int maxi = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 1)
        {
            cnt++;
            maxi = max(maxi, cnt);
        }
        else
        {
            cnt = 0;
        }
    }

    return maxi;
}

int main()
{
    vector<int> arr = {1, 0, 1, 1, 0, 1};

    int ans = maxConss(arr);
    cout << ans << endl;
    return 0;
}