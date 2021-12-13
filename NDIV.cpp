#include <bits/stdc++.h>
using namespace std;

vector<bool>isprime(31623,true);
vector<int>prime;
void pre()
{
	isprime[0]=isprime[1]=false;
	for(int i=2;i<=31623;i++)
	{
		if(isprime[i])
		{
			prime.push_back(i);
			for(int j=i*i;j<=31623;j+=i)
				isprime[j]=false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int a,b,c,ans=0;
	cin>>a>>b>>c;
	for(int i=a;i<=b;i++)
	{
		long long int mul=1;
		int s=sqrt(i);
		int temp=i;
		for(int j=0; prime[j]<=s && j<prime.size(); j++)
		{
			if(i%prime[j]==0)
			{
				int k=1;
				i/=prime[j];
				while(i%prime[j]==0)
				{
					i/=prime[j];
					k++;
				}
				mul*=(k+1);
			}
		}
		if(i>1)
			mul<<=1;

		if(mul==c)
			ans++;

		i=temp;
	}
	cout<<ans;
}