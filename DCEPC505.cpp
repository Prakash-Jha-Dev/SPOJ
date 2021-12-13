#include <bits/stdc++.h>
using namespace std;
vector< int >isprime(1200000);
vector<long long>prime;
vector<long long>ans;
void pre()
{	
	int n = 12000000;
	prime.push_back(2);
	prime.push_back(3);
	unsigned int k, i, j, add, sq=4000;
	for(k=6; k<12000006 ; k+=6)
	{
		i = k - 1;
		if(!( isprime[ (i>>6)+1 ] & ( 1<<( (i - ((i>>6)<<6))>>1 ) ) ))
		{
			prime.push_back(i);
			if(i<sq)
			{
				add=(i<<1);
				for(j=i*i; j<=n; j+=add) isprime[(j>>6)+1] |= ( 1<<( (j - ((j>>6)<<6) )>>1 ) );
			}
		}
 
		i = k + 1;
		if(!( isprime[ (i>>6)+1 ] & ( 1<<( (i - ((i>>6)<<6))>>1 ) ) ))
		{
			prime.push_back(i);
			if(i<sq)
			{
				add=(i<<1);
				for(j=i*i; j<=n; j+=add) isprime[(j>>6)+1] |= ( 1<<( (j - ((j>>6)<<6) )>>1 ) );
			}
		}
	}
	for(int i=0;i<prime.size();i++)
	{
		for(int j=i+1;j<prime.size();j++)
		{
			if(prime[i]*prime[j]>12000000) break;
			else ans.push_back(prime[i]*prime[j]);
		}
	}
	sort(ans.begin(),ans.end());
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// clock_t timer = clock();
	pre();
	int test;
	cin>>test;
	int n;

	while(test--)
	{
		cin>>n;
		
		cout<<ans[n-1]<<"\n";
	}
	// cout<<float(clock()-timer)/CLOCKS_PER_SEC<<"\n";
	return 0;
}

