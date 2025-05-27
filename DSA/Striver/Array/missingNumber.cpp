#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &a)
{
    int size = a.size();
    int xor1 = 0;
    int xor2 = 0;

    // for (int i = 1; i <= size; i++)
    // {
    //     xor1 = xor1 ^ i;
    // }

    for (int i = 0; i < size - 1; i++)
    {
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ size;

    return xor1 ^ xor2;
}

int main()
{
    vector<int> a = {1, 2, 3, 5};
    int ans = missingNumber(a);

    cout << ans << "";
    return 0;
}