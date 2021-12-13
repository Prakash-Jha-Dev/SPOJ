#include <bits/stdc++.h>
using namespace std;
#define lld long long

lld modexp(lld base, lld power, lld mod=10000007)
{
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
	// ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long n,k;
	while(1)
	{
		cin>>n>>k;
		if(n==0 && k==0) break;
		long long ans=(modexp(n-1,k))*2 + modexp(n,k) + 2*(modexp(n-1,n-1))+modexp(n,n);
		ans%=10000007;
		cout<<ans<<"\n";
	}
}