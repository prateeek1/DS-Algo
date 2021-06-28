#include<bits/stdc++.h>
using namespace std;


// Top Down DP
int  lcs(string a, string b, int i, int j, vector<vector<int>> &dp)
{
	if (i == a.length() || j == b.length())
		return 0;

	if (a[i] == b[j])
	{
		dp[i][j] = 1 + lcs(a, b, i + 1, j + 1, dp);
	}

	if (dp[i][j] != -1)
		return dp[i][j];

	int op1 = lcs(a, b, i + 1, j, dp);
	int op2 = lcs(a, b, i, j + 1, dp);

	dp[i][j] = max(op1, op2);

	return dp[i][j];
}



int max_profit(int prices[], int n)
{
	int dp[n + 1];
	dp[0] = 0;

	for (int len = 1; len <= n; len++)
	{
		int ans = INT_MIN;
		for (int i = 0; i < len; i++)
		{
			int cut = i + 1;
			int current_ans = prices[i] + dp[len - cut];
			ans = max(ans, current_ans);
		}

		dp[len] = ans;
	}

	return dp[n];

}


int main()
{
	int prices[] = {3, 5, 8, 9, 17, 17, 20};
	int n = sizeof(prices) / sizeof(int);

	cout << max_profit(prices, n);

}