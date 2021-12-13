#include <bits/stdc++.h>
using namespace std;

//Computes primes till N using bit sieve.
#define N 100001001
int isprime[(N>>6)+3];
vector<int> prime_list(6500000);

void pre()
{	
	prime_list[0] = 2;
	int cnt = 1;
	int sq=sqrt(N)+1;

	for(unsigned int i=3;i<=N;i+=2)
	{
		if(!( isprime[ (i>>6)+1 ] & ( 1<<( (i - ((i>>6)<<6))>>1 ) ) ))
		{
			prime_list[cnt++]=i;
			if(i<sq)
			{
				unsigned int add=(i<<1);
				for(unsigned int j=i*i; j<=N; j+=add) isprime[(j>>6)+1] |= ( 1<<( (j - ((j>>6)<<6) )>>1 ) );
			}
		}
	}
}
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
	pre();
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;

	while(t--)
	{
		int n,i,m;
		cin>>n>>m;
		// m = 1000000007;

		lld fact = 1,cnt,div,temp,sq = sqrt(n);

		for(i=0; prime_list[i]<=sq; i++)
		{
			cnt = 1;
			div = prime_list[i];
			while(div <= n)
			{
				cnt+=n/div;
				div*=prime_list[i];
			}
			// cout<<prime_list[i]<<" "<<cnt<<"\n";
			fact=(fact*cnt)%m;
		}

		vector<int>::iterator it,bt;
		it = upper_bound(prime_list.begin(),prime_list.end(),sq);

		if(sq*sq != n) sq++;
		for(i=sq-1; i>0; i--)
		{
			bt = upper_bound(prime_list.begin(),prime_list.end(),n/i);
			if(*bt > *it)
			{
				temp = modexp(i+1,(bt - it),m);
				fact = (fact*temp)%m;
				it = bt;
				// cout<<i<<" :: "<<temp<<"\n";
			}
		}
		cout<<fact<<"\n";
	}
	return 0;
}