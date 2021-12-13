#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long long

lld modexp(lld base, lld power, lld mod=10)
{
	base%=mod;
	lld res=1;
	while(power)
	{
		if(power&1) res=(res*base)%mod;
		power>>=1;
		base=(base*base)%mod;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int test;
	cin>>test;
	lld n,m;

	while(test--)
	{
		cin>>n>>m;
		cout<<modexp(n,m)<<"\n";
	}
}