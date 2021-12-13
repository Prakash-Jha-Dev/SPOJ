#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector< int >isprime(10001,1);
void pre()
{
	for(int i=2;i<101;i++)
	{
		if(isprime[i])
		{
			for(int j=i*i;j<10001;j+=i)
			{
				isprime[j]=0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	pre();
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int x;
		cin>>x;

		if(x==3) cout<<i<<":2\n";
		else if(isprime[x]) cout<<i<<":"<<1<<"\n";
		else cout<<i<<":NOTPRIME\n";
	}
}

