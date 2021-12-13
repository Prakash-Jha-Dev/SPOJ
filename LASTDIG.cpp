#include <bits/stdc++.h>
using namespace std;
#define lld long long

lld modexp(lld base, lld power, lld mod=1000000007)
{
	lld res=1;
	while(power)
	{
		if(power&1) res=(res*base)%10;
		power>>=1;
		base=(base*base)%10;
	}
	return res%10;
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b;
		cin>>a>>b;
		cout<<modexp(a%10,b)<<"\n";
	}
}