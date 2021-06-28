#include<bits/stdc++.h>
using namespace std;


// TOP DOWN APPROACH
// Min Steps to reach one if we can do n/2 n/3 or n-1
int minSteps(int n, int dp[])
{
	if (n <= 1)
		return 0;

	if (dp[n] != 0)
		return dp[n];

	int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

	if (n % 2 == 0)
		op1 = minSteps(n / 2, dp) + 1;
	if (n % 3 == 0)
		op2 = minSteps(n / 2, dp) + 1;

	op3 = minSteps(n - 1, dp) + 1;

	int ans = min(min(op1, op2), op3);
	dp[n] = ans;
}



// Bottom Up Approach

int minStepsBU(int n)
{
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));

	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		int op1, op2, op3;
		op1 = op2 = op3 = INT_MAX;
		if (i % 3 == 0)
			op1 = dp[i / 3] + 1;
		if (i % 2 == 0)
			op2 = dp[i / 2] + 1;

		op3 = dp[i - 1] + 1;

		dp[i] = min(min(op1, op2), op3);
	}
	return dp[n];
}

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





int main()
{
	string a = "ABCD";
	string b = "ABEDG";
	int n1 = a.length();
	int n2 = b.length();
	vector<vector<int>>dp(n1, vector<int>(n2, -1));

	cout << lcs(a, b, 0, 0, dp) << endl;


	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

}