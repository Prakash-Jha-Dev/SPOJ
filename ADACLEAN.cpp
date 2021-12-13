#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define lld unsigned long long
lld mod1 = 1000000007;
lld mod2 = 1190494759;

lld inv1, inv2;

lld modexp(lld base, lld power, lld mod)
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
	return modexp(num,mod-2,mod);
}

vector< lld > m1(100005),m2(100005);
void pre()
{
	m1[0]=29;
	m2[0]=31;

	for(int i=1;i<100005;i++)
	{
		m1[i] = (m1[i-1]*m1[0])%mod1;
		m2[i] = (m2[i-1]*m2[0])%mod2;
	}

	inv1 = invmod(m1[0],mod1);
	inv2 = invmod(m2[0],mod2);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int test;
	cin>>test;
	int l,k;
	string s;

	while(test--)
	{
		cin>>l>>k>>s;
		if(k>l) 
		{
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<l;i++) s[i]-='a';

		set< vector<lld> >task;
		lld a=0,b=0;

		for(int i=0;i<k-1;i++)
		{
			a = (a + m1[i]*s[i])%mod1;
			b = (b + m2[i]*s[i])%mod2;
		}

		for(int i=k-1;i<l;i++)
		{

			a = (a + m1[k-1]*s[i])%mod1;
			b = (b + m2[k-1]*s[i])%mod2;
			a = (a * inv1)%mod1;
			b = (b * inv2)%mod2;

			task.insert({a,b});

			a = (a - s[i-k+1] +mod1)%mod1;
			b = (b - s[i-k+1] +mod2)%mod2;
		}
		cout<<task.size()<<"\n";
	}
}