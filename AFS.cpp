#include <bits/stdc++.h>
using namespace std;
#define lld long long

long long ans[1000001];
long long part[1000001];
void pre()
{
	for(int i=2;i<1000001;i++)
	{
		for(int j=i+i;j<1000001;j+=i)
		{
			part[j]+=i;
		}
	}
	for(int i=2;i<1000001;i++) ans[i]=ans[i-1]+part[i]+1;
}


int main()
{
	// ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int t,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		printf("%lld\n",ans[x]);
	}
	return 0;
}