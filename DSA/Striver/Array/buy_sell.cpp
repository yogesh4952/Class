#include <bits/stdc++.h>
using namespace std;
int maxProfits(vector<int> &arr)
{
	int mini = arr[0];
	int maxProfit = 0;

	int n = arr.size();

	for (int i = 0; i < n; i++)
	{
		int cost = arr[i] - mini;
		maxProfit = max(maxProfit, cost);
		mini = min(mini, arr[i]);
	}
	return maxProfit;
}

int main()
{
	vector<int> arr = {5, 4, 21, 1, 4};
	cout << maxProfits(arr);

	return 0;
}

int sort(vector<int>&arr){

}


