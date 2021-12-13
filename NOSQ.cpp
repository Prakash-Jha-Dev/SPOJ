#include <bits/stdc++.h>
using namespace std;

vector< vector<int> >ans(10, vector<int>(100001));

void pre()
{
	vector<int>sq(100001,1);
	vector<int>prime(100001,1);
	for(int i=2; i<3167; i++)
	{
		if(prime[i])
		{
			for(int j=i*i; j<100001; j+=i) prime[j]=0;
		}
	}
	
	for(int i=2; i<3167; i++)
	{
		if(prime[i])
		{
			int add = i*i;
			for(int j=add; j<100001; j+=add) sq[j]=0;
		}
	}
	
	for(int i=1;i<100001;i++)
	{
		if(sq[i]==0) continue;
		
		set<int>add;
		for(int j=i; j; j/=10)
		{
			add.insert(j%10);
		}
		for(auto x:add) ans[x][i]+=1;
	}
	
	for(int i=1; i<100001; i++)
	{
		for(int d=0; d<10; d++) ans[d][i]+=ans[d][i-1];
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
		int a,b,d;
		cin>>a>>b>>d;
		
		cout<<(ans[d][b] - ans[d][a-1])<<"\n";
	}
	return 0;
}