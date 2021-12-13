#include <bits/stdc++.h>
using namespace std;

long long sum(long long x, long long y) //sum i in range(x,y]
{
	long long ans1=(y*(y+1))/2;
	long long ans2=(x*(x+1))/2;
	return ans1-ans2;
}

void solve()
{
	long long n;
	cin>>n;

	int s=sqrt(n);
	long long prev=n,ans=0,temp;
	for(int i=1;i<=s;i++)
	{
		if((n/i)>s)
			ans=ans+(n/i *i)+ i*(sum(n/(i+1), n/i));
		else
			ans=ans+(n/i *i);
	}
	cout<<ans%1000000007<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;

	for(int test=1;test<=t;test++)
	{
		solve();
	}
}