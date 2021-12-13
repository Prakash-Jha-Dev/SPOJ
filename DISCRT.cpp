#include <bits/stdc++.h>
using namespace std;

long long modexp(long long base, long long power,int mod)
{
	long long res=1;
	while(power)
	{
		if(power&1) res=(res*base)%mod;
		power>>=1;
		base=(base*base)%mod;
	}
	return res;
}

void get_prime_factor(int n, auto& fact)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			fact.push_back(i);
			n/=i;
			while(n%i==0)
			{
				n/=i;
			}
		}
	}
	if(n>1) fact.push_back(n);
}

int calculate_phi(int n, auto& fact)
{
	for(auto x:fact)
		n-=(n/x);
	return n;
}

int get_primitive_root(int p)
{
	vector<int>fact;
	get_prime_factor(p,fact);
	int phi=calculate_phi(p,fact);
	int n=phi;
	fact.clear();
	get_prime_factor(phi,fact);


	for(int i=2; i<=p; i++)
	{
		bool flag=true;
		for(int j=0; j<fact.size() && flag; j++)
		{
			flag&=modexp(i,phi/fact[j],p)!=1;
		}
		if(flag) return i;
	}
	return -1;
}

int get_discrete_logarithm(int b, int a, int n)
{
	int s=ceil(sqrt(float(n-1.0)));
	unordered_map<int,int>root_n_kth_power;
	int temp1=1;
	int temp2=modexp(b,s,n);

	for(int i=1;i<=s;i++)
	{
		temp1=(temp1*temp2)%n;
		root_n_kth_power[temp1]=i;
	}

	temp1=1;
	int i;
	for(i=0;i<=s;i++)
	{
		temp2=(a*temp1)%n;
		if(root_n_kth_power.count(temp2))
		{
			long long z=root_n_kth_power[temp2];
			int ans=(z*s - i + n)%n;
			return ans;
		}
		temp1=(temp1*b)%n;
	}
	return 0;
}

pair<int,int> get_discrete_root(int n, int k, int a)
{
	int g=get_primitive_root(n);
	int x=g;
	g=modexp(g,k,n);

	int y=get_discrete_logarithm(g,a,n);
	return {y,x};
}

int main()
{
	int n,k,a;
	cin>>n>>k>>a;
	auto z=get_discrete_root(n,k,a);
	int f=z.first;
	int g=z.second;

	if(f==0)
	{
		cout<<0;
	}
	else
	{
		vector<int>sol;

		int delta=(n-1)/__gcd(k,n-1);

		for(int i=f%delta; i<n-1; i+=delta)
			sol.push_back(modexp(g,i,n));

		sort(sol.begin(),sol.end());

		cout<<sol.size()<<"\n";
		for(auto x:sol)
			cout<<x<<"\n";
	}

}