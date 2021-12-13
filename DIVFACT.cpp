#include <bits/stdc++.h>
using namespace std;
#define SIZE 100001
#define MOD 1000000007

vector< long long > prime;
vector< bool > isprime(SIZE,1);
void pre()
{
	isprime[0]=isprime[1]=0;
	// int sq=sqrt(SIZE)+1;
	for(long long i=2;i<SIZE;i++)
	{
		if(isprime[i])
		{
			prime.emplace_back(i);
			for(long long j=i*i; j<SIZE; j+=i)
				isprime[j]=0;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int m=n+1;

    	long long ans=1;
    	for(int i=0; i<prime.size() && prime[i]<m ; i++)
    	{
    		long long fact=1;
    		for(long long j=prime[i]; j<m; j*=prime[i])
    		{
    			fact+=(n/j);
    		}
    		ans=(ans*(fact))%MOD;
    	}
    	cout<<ans<<"\n";
    }
}