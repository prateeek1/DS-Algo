#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[100];

	int n,m;
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
	}

	bool dp[n+1][m+1];

	dp[0][0]=1;

	for(int i=0;i<=m;i++)
		dp[0][i]=0;

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(j<a[i]) 
			  dp[i][j]=dp[i-1][j];

			                     // while element smaller copy from previous dp
				

			 else
			 {
			 	int need=j-a[i];
			 	if(dp[i-1][j]==1 || dp[i-1][need])
			 		dp[i][j]=1;

			 	else
			 		dp[i][j]=0;
			 }                                //else calculate need
		}
	}

	bool ans=dp[n][m];

	if(ans==1)
		cout<<"YES";

	else
		cout<<"NO";




}