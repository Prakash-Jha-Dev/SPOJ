#include <bits/stdc++.h>
using namespace std;


void solve()
{
	long long n;
	cin>>n;

	int s=sqrt(n);
	long long prev=n,ans=0,temp;
	for(int i=1;i<=s;i++)
	{
		if((n/i)>s)
			ans=ans+(n/i)+ i*(abs(n/(i+1)- n/i));
		else
			ans=ans+(n/i);
	}
	cout<<ans<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1;

	for(int test=1;test<=t;test++)
	{
		solve();
	}
}