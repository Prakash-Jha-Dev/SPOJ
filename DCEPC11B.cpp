#include <bits/stdc++.h>
#include <fstream>
#define lld long long int
using namespace std;
#define MOD 1000000007

lld modexp(lld base, lld power, lld mod=1000000007)
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

lld invmod(lld num, lld mod=1000000007)
{
	if(num == 1) return 1;
	return modexp(num,mod-2,mod);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;

	while(t--)
	{
		lld n,p,ans;
		cin>>n>>p;

		if(n>=p)
		{
			ans = 0;
		}
		else
		{
			ans = p-1;
			for(int i=p-1;i>n;i--)
			{
				(ans*=invmod(i,p))%=p;
			}
		}
		cout<<ans<<"\n";
	}
}