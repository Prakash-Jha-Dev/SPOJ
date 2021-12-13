#include <bits/stdc++.h>
using namespace std;
#define lld long long

vector<double> fact(3000005);
void pre()
{
	fact[0]=0;
	fact[1]=0;
	for(int i=2;i<3000005;i+=1)
		fact[i]=(fact[i-1]+log(i+0.0));
}

double logpow(double base, int exp)
{
	double res=0.0;
	while(exp)
	{
		if(exp&1)	res+=base;
		exp>>=1;
		base+=base;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();

	int t;
	cin>>t;

	while(t--)
	{
		int x;
		cin>>x;

		int l=2*x, r=3*x;
		while(l<r)
		{
			int m=(l+r)>>1;
			if(fact[m] <= logpow(log(x+0.0), m))
			{
				l=m+1;
			}
			else
			{
				r=m;
			}
		}
		cout<<l<<"\n";
	}
}
	