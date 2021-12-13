#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long long

#define N 10000001
vector<bool>isprime(N,1);
vector<int>prime_list;

void pre()
{	
	prime_list.reserve(700000);
	isprime[0]=isprime[1]=0;
	for(int i=2;i<N;i++)
	{
		if(isprime[i])
		{
			prime_list.push_back(i);
			if(i<3164)
			{
				for(int j=i*i;j<N;j+=i) isprime[j]=0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int test;
	cin>>test;
	lld l,r,k;

	while(test--)
	{
		cin>>l>>r>>k;
		if(l>r) swap(l,r);
		int last = r-k+1;
		int ans = 0;
		for(auto it=lower_bound(prime_list.begin(),prime_list.end(),l); it !=prime_list.end() && *it < last; it++)
		{
			if(isprime[(*it + k)] ) ans++;
		}
		cout<<ans<<"\n";
	}
}