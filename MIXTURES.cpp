#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
	vector<int>arr(n+1), sum(n+1);
	for(int i=1;i<=n;i++)	{cin>>arr[i];sum[i]=sum[i-1]+arr[i];}

	vector< vector<int> >dp(n+1, vector<int>(n+1, 100000000));
	for(int i=1;i<=n;i++) dp[i][i]=0;

	for(int i=1;i<n;i++)
		for(int j=1;j+i<=n;j++)
			for(int k=j;k<j+i;k++)
				dp[j][j+i]=min(dp[j][j+i], ((sum[k]-sum[j-1])%100) * ((sum[j+i]-sum[k])%100) + dp[j][k] + dp[k+1][j+i]);
	cout<<dp[1][n]<<"\n";
}

int main()
{
	int n;
	while(cin>>n) solve(n);
}