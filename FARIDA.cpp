#include <bits/stdc++.h>
using namespace std;

bool done[100005];
long long sol[100005];
long long arr[100005],n;

void solve(int i)
{
	if(done[i]) return;
	done[i]=1;

	if(i==n)
	{
		sol[i]=arr[i];
	}
	else if(i==n-1)
	{
		solve(i+1);
		sol[i]=max(arr[i],sol[i+1]);
	}
	else if(i==n-2)
	{
		solve(i+1);
		solve(i+2);
		sol[i]=max(arr[i]+sol[i+2],sol[i+1]);
	}
	else
	{
		solve(i+1);
		solve(i+2);
		solve(i+3);
		sol[i]=max({arr[i]+sol[i+2],sol[i+1],sol[i+3]+arr[i]});
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cout<<"Case "<<i<<": ";
		memset(sol,0,sizeof sol);
		memset(done, 0, sizeof done);
		cin>>n;

		if(n==0)
		{
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++) cin>>arr[i];
		solve(1);
		cout<<sol[1]<<"\n";
	}
}