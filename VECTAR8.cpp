#include <bits/stdc++.h>
using namespace std;
#define lld long long
vector<int>ans(1000001,0);
vector<bool>isprime(1000001,1),ha(1000001,0);

void solve(int i, bool flag, int mul)
{
	if(!isprime[i]) return;
	ha[i]=flag;

	mul*=10;

	if(mul==1000000) return;
	for(int j=1;j<=9;j++) solve(j*mul+i, flag, mul);
}

void pre(int n)
{	
	isprime[0]=isprime[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(isprime[i] && i<1000)
		{
			for(int j=i*i;j<=n;j+=i) isprime[j]=0;
		}
	}

	for(int i=1;i<=9;i++)  solve(i,1,1);
	for(int i=1;i<=n;i++) ans[i]=ans[i-1]+ha[i];
}

int main()
{
	// clock_t timer=clock();
	pre(1000000);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int test,n;
	cin>>test;
	while(test--)
	{
		cin>>n;
		cout<<ans[n]<<"\n";
	}
	// cout<<float(clock() - timer)/CLOCKS_PER_SEC<<"\n";
}