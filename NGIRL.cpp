#include <bits/stdc++.h>
using namespace std;
vector< int >isprime(1565);
vector<long long>ans;
void pre()
{	
	int n = 100000;
	ans.push_back(4);
	ans.push_back(9);
	unsigned int k, i, j, add, sq=10001;
	for(k=6; k<100000 ; k+=6)
	{
		i = k - 1;
		if(!( isprime[ (i>>6)+1 ] & ( 1<<( (i - ((i>>6)<<6))>>1 ) ) ))
		{
			ans.push_back(1LL*i*i);
			if(i<sq)
			{
				add=(i<<1);
				for(j=i*i; j<=n; j+=add) isprime[(j>>6)+1] |= ( 1<<( (j - ((j>>6)<<6) )>>1 ) );
			}
		}
 
		i = k + 1;
		if(!( isprime[ (i>>6)+1 ] & ( 1<<( (i - ((i>>6)<<6))>>1 ) ) ))
		{
			ans.push_back(1LL*i*i);
			if(i<sq)
			{
				add=(i<<1);
				for(j=i*i; j<=n; j+=add) isprime[(j>>6)+1] |= ( 1<<( (j - ((j>>6)<<6) )>>1 ) );
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// clock_t timer = clock();
	pre();
	int test;
	cin>>test;
	long long n,k;
	while(test--)
	{
		cin>>n>>k;
		auto it=upper_bound(ans.begin(),ans.end(),n);
		auto bt=upper_bound(ans.begin(),ans.end(),k);
		if(it-bt>=0)
		cout<<it-ans.begin()<<" "<<it-bt<<"\n";
		else
			cout<<it-ans.begin()<<" "<<0<<"\n";
	}
	// cout<<float(clock()-timer)/CLOCKS_PER_SEC<<"\n";
	return 0;
}

