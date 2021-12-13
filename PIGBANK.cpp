#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int empty,full;
	cin>>empty>>full;

	if(full<empty)
	{
		cout<<"This is impossible.\n";
		return;
	}
	else if(full==empty)
	{
		cout<<"The minimum amount of money in the piggy-bank is "<<0<<".\n";
		return;
	}
	full-=empty;

	int n;
	cin>>n;
	vector< pair<int,int> >arr(n+1);
	for(int i=1;i<=n;i++) cin>>arr[i].first>>arr[i].second;

	vector<long long int>dp(full+1,10000000000);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=full-arr[i].second;j++)
		{
			dp[j+arr[i].second]=min(dp[j+arr[i].second], dp[j]+arr[i].first);
		}
	}
	if(dp[full]==10000000000)
		cout<<"This is impossible.\n";
	else
		cout<<"The minimum amount of money in the piggy-bank is "<<dp[full]<<".\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}