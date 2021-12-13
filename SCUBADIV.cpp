#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int t,a,n,x,y,z;
	cin>>t>>a;
	vector< vector<int> >dp(t+1, vector<int>(a+1,999999));
	dp[0][0]=0;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>z;
		for(int j=t;j>=0;j--)
		{
			for(int k=a;k>=0;k--)
			{
				dp[j][k]=min(dp[j][k], dp[max(j-x,0)][max(k-y,0)]+z);
			}
		}
	}
	cout<<dp[t][a]<<"\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	solve();	
}