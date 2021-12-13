#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009

long long tab[1001][1001];
vector< vector<int> >fact(1001);
void pre(int n, int k)
{
	for(int i=1;i<=k;i++)
	{
		for(int j=i;j<=k;j+=i)
		{
			fact[j].push_back(i);
			if(j!=i)
			fact[i].push_back(j);
		}
	}
	for(int i=1;i<=k;i++) {tab[1][i]=1;}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			for(auto k:fact[j])
			{
				tab[i][j]=(tab[i][j]+tab[i-1][k])%MOD;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int x,y;
	cin>>x>>y;
	pre(x,y);
	long long ans=0;
	for(int i=1;i<=y;i++) ans=(ans+tab[x][i])%MOD;
	cout<<ans%MOD;
}