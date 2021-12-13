#include <fstream>
#include <bits/stdc++.h>
using namespace std;
#define lld long long

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	vector<int>v(50);
	for(int i=1;i<50;i++) v[i]=(i*i*i);

	vector<int> dp(100001,100000);
	dp[0]=0;
	for(int i=0;i<100000;i++)
	{
		for(int j=1;j<v.size() && (v[j]+i)<100001 ;j++)
		{
			dp[v[j]+i]=min(dp[i]+1,dp[v[j]+i]);
		}
	}

	int test=0;
	while(cin>>n)
	{
		test++;
		cout<<"Case #"<<test<<": "<<dp[n]<<"\n";
	}
}