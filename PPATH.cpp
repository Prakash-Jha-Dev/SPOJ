#include <bits/stdc++.h>
using namespace std;

vector<int>prime;

vector< vector<int> >adj;

int ans=10000;

void pre()
{
	vector<bool>isprime(10000,1);
	for(int i=3;i<101;i+=2)
	{
		if(isprime[i])
		{
			for(int j=i*i;j<10000;j+=i)
				isprime[j]=0;
		}
	}
	for(int i=1001;i<10000;i+=2)
		if(isprime[i])
			prime.emplace_back(i);

	adj.resize(prime.size());
	int edges=0;
	for(int i=0;i<prime.size();i++)
	{
		for(int j=i+1;j<prime.size();j++)
		{
			int change=0;
			int x=prime[i];
			int y=prime[j];
			while(x)
			{
				int r1=x%10;
				int r2=y%10;
				x/=10;
				y/=10;
				change+=(r1!=r2);
			}
			if(change==1)
			{
				adj[j].push_back(i);
				adj[i].push_back(j);
				edges++;
			}
		}
	}
}

queue< pair<int,int> >node;

int target;

void dfs(int x, int y, auto& vis)
{
	if(x==target)
	{
		ans=min(ans,y);
		while(!node.empty()) node.pop();
		return;
	}
	for(auto z:adj[x])
	{
		if(!vis[z])
		{
			node.push({z,y+1});
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
		int p1,p2;
		cin>>p1>>p2;

		int x,y;
		x=lower_bound(prime.begin(),prime.end(),p1)-prime.begin();
		y=lower_bound(prime.begin(),prime.end(),p2)-prime.begin();
		target=y;

		ans=10000;

		vector<bool>visited(prime.size()+1,0);

		node.push({x,0});
		while(!node.empty())
		{
			int p=node.front().first;
			int q=node.front().second;
			node.pop();
			dfs(p,q,visited);
		}


		if(ans>9999)
			cout<<"Impossible\n";
		else
			cout<<ans<<"\n";
	}
}