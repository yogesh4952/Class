#include <bits/stdc++.h>
using namespace std;

void moveLast(vector<int> &arr)
{
    int zeroPostion = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            zeroPostion = i;
            break;
        }
    }

    if (zeroPostion == -1)
    {
        printf("There is no zero element in the array\n");
        return;
    }

    for (int i = zeroPostion; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            arr[zeroPostion] = arr[i];
            zeroPostion++;
        }
    }

    while (zeroPostion < arr.size())

    {
        arr[zeroPostion++] = 0;
        /* code */
    }
}

int main()
{

    vector<int> arr = {1, 0, 0, 2, 3, 4, 5, 0};

    moveLast(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}