#include <bits/stdc++.h>
using namespace std;
#define lld long long

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

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int test;
	cin>>test;
	lld num,sq,rem,ans;
	while(test--)
	{
		cin>>num;
		if(num == 1)
		{
			cout<<1<<"\n";
			continue;
		}
		rem = num%3;
		if(!rem) ans=modexp(3,num/3);
		else if(rem==1) ans=4*modexp(3,(num-4)/3);
		else ans=2*modexp(3,(num-2)/3);
		cout<<ans%1000000007<<"\n";
	}

}