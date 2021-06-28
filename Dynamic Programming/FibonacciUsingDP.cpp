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

int main()
{
	int dp[100] = {0};
	cout << minSteps(5, dp) << endl;
	cout << minStepsBU(5) << endl;

}