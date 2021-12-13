#include <bits/stdc++.h>
using namespace std;

long long dp[1048576][20];

void calc(int mask,int i, int n, auto& task)
{
	if(dp[mask][i]!=-1) return ;

	long long ans=0;
	if(i==n)
	{
		for(int j=0;j<=n;j++)
		{
			if(task[i][j] && (mask&(1<<(n-j)))==0)
			{
				ans++;
			}
		}
		dp[mask][i]=ans;
		return;
	}

	for(int j=0;j<=n;j++)
	{
		if(task[i][j] )
		{
			if( (mask&(1<<(n-j)))!=0 )	continue;
			calc(mask|(1<<(n-j)) , i+1, n, task );
			ans+=dp[mask|(1<<(n-j))][i+1];
		}
	}
	dp[mask][i]=ans;
}

void solve()
{
	memset(dp,-1,sizeof dp);
	int n;
	cin>>n;
	vector< vector<int> >task(n, vector<int>(n));
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>task[i][j];

	calc(0,0,n-1,task);
	cout<<dp[0][0]<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}