#include <bits/stdc++.h>
using namespace std;

void solve(int maxval, int n)
{
	int dp[n+1][maxval+1];
	vector< pair<int,int> >party;
	party.push_back({0,0});
	memset(dp, 0, sizeof dp);

	for(int i=1;i<=n;i++) 
	{
		int x,y;
		cin>>x>>y;
		party.push_back({x,y});
	}

	for(int i=1;i<=n;i++)
	{
		for(int f=0;f<=maxval;f++)
		{
			if(party[i].first <= f)
			{
				dp[i][f]=max({dp[i-1][f-party[i].first]+party[i].second, dp[i][f], dp[i-1][f]});
			}
			else
				dp[i][f]=max(dp[i-1][f],dp[i][f]);
		}
	}

	int cost=0,m=0;
	for(int i=maxval;i>=1;i--)
	{
		if(dp[n][i]>=m)
		{
			m=dp[n][i];
			cost=i;
		}
	}
	cout<<cost<<" "<<m<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   	int n,m;
   	while(1)
   	{
   		cin>>n>>m;
   		if(n==0) break;
   		solve(n,m);
   	}
}