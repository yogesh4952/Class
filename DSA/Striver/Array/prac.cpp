#include <bits/stdc++.h>
using namespace std;

int maxprofits(vector<int> &arr)
{
	int mini = arr[0];
	int maxProfit = 0;

	for (int i = 1; i < arr.size(); i++)
	{
		int cost = arr[i] - mini;
		maxProfit = max(cost, maxProfit);
		mini = min(arr[i], mini);
	}

	return maxProfit;
}

int main()
{
	vector<int> arr = {7, 1, 5, 3, 6, 4};
	int ans = maxprofits(arr);
	cout << ans << endl;

	return 0;
}
