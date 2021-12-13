#include <bits/stdc++.h>
using namespace std;

vector<long long>prime;
vector<bool>isprime(1000001,1);
void pre()
{
	for(long long i=2;i<1000001;i++)
	{
		if(isprime[i])
		{
			prime.push_back(i);
			for(long long j=i*i;j<1000001;j+=i)
				isprime[j]=0;
		}
	}
}

void solve()
{
	unsigned long long x,y;
	cin>>x>>y;

	bool flag=true;
	if(__gcd(x,y)>1) {flag=false;x=y=0;}

	for(int i=0;i<prime.size() && x>1;i++)
	{
		if(x%prime[i]==0)
		{
			int count=1;
			x/=prime[i];
			while(x%prime[i] ==0)
			{
				x/=prime[i];
				count++;
			}
			if(count>=2)
			{
				flag=false;
				x=y=0;
			}
		}
	}
	for(int i=0;i<prime.size() && y>1;i++)
	{
		if(y%prime[i]==0)
		{
			int count=1;
			y/=prime[i];
			while(y%prime[i] ==0)
			{
				y/=prime[i];
				count++;
			}
			if(count>=2)
			{
				flag=false;
				y=0;
			}
		}
	}
	if(x>1)
	{
		long long t1=sqrt(x);
		if(t1*t1==x) flag=false;
	}
	if(y>1)
	{
		long long t1=sqrt(y);
		if(t1*t1==y) flag=false;
	}
	flag?cout<<"YES\n":cout<<"NO\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();

	int t;
	cin>>t;
	while(t--)
	solve();
}