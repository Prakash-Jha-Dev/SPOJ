#include <bits/stdc++.h>
using namespace std;
#define lld long long

vector<int>phi(1000001);
vector<long long>dphi(1000001,0);
vector<long long>sum(1000001,0);
void pre()
{
	for(int i=1;i<1000001;i++) phi[i]=i;
	for(int i=2;i<1000001;i++)
	{
		if(phi[i]==i)
		{
			for(int j=i;j<1000001;j+=i) phi[j]-=(phi[j]/i);
		}
	}

	for(int i=1;i<1000001;i++)
	{
		for(int j=i;j<1000001;j+=i)
		{
			dphi[j]+=(i*phi[j/i]);
		}
	}

	for(int i=2;i<1000001;i++)
	{
		sum[i]=sum[i-1]+dphi[i];
	}

	for(long long i=2;i<1000001;i++)
	{
		sum[i]-=(i*(i+1)/2 -1);
	}
}

int main()
{
	pre();
	// ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	while(1)
	{
		cin>>n;
		if(!n) break;
		cout<<sum[n]<<"\n";
	}
}