#include <bits/stdc++.h>
using namespace std;
#define SIZE 10000001

vector<__int128>prime;
vector<bool>isprime(SIZE,1);
void pre()
{
	prime.reserve(4000000);
	int sq=sqrt(SIZE);
	for(int i=2;i<=SIZE;i++)
	{
		if(isprime[i])
		{
			prime.emplace_back(i);
			if(i<=sq)
			{
				for(int j=i*i;j<SIZE;j+=i)
					isprime[j]=0;
			}
		}
	}
}

long long ans=0;

void non_p_free(long long idx, __int128 div, long long num, int p)
{
	if(div > num) return;
	if(p&1)
		ans+=(num/div);
	else
		ans-=(num/div);

	for(int i=idx; i<prime.size(); i++) 
	{
		__int128 temp=prime[i]*prime[i]*div;
		if( temp > num) break;
		non_p_free(i+1, temp , num, p+1);
	}
}

void solve()
{
	long long int n;
	cin>>n;
	ans=0;
	int sq=sqrt(n);
	for(int i=0;prime[i]<=sq; i++)
	non_p_free(i+1,prime[i]*prime[i],n,1);

	cout<<n-ans<<"\n";
}

int main()
{
	pre();
	// ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}