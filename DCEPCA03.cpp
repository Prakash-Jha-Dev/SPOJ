#include <bits/stdc++.h>
using namespace std;
#define lld long long
#define SIZE 10001

vector<int>phi(SIZE);
vector<long long>sum(SIZE);

void pre()
{
	for(int i=1;i<SIZE;i++) phi[i]=i;
	for(int i=2;i<SIZE;i++)
	{
		if(phi[i]==i)
		{
			for(int j=i;j<SIZE;j+=i) phi[j]-=(phi[j]/i);
		}
	}
	for(int i=1;i<SIZE;i++) sum[i]=sum[i-1]+phi[i];
}

int main()
{
	// clock_t timer=clock();
	pre();
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int test,n;
	cin>>test;
	while(test--)
	{
		cin>>n;
		cout<<sum[n]*sum[n]<<"\n";
	}
	// cout<<float(clock() - timer)/CLOCKS_PER_SEC<<"\n";
}