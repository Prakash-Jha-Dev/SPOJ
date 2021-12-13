#include <bits/stdc++.h>
using namespace std;

int data[1001][1001];

int solve(int n, int k)
{
	if(n==1) return 1;
	else 
	{
		data[n][k] = (solve(n-1,k)+k-1)%n+1;
		return data[n][k];
	}
}

void pre()
{
	for(int i=1;i<=1000;i++)
	{
		data[1][i]=1;
		solve(1000,i);
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
		int n,j,k;
		cin>>n>>j>>k;
		cout<<(j+data[n][k]-1)%(n) +1<<"\n";
	}
}