#include <bits/stdc++.h>
using namespace std;

#define SIZE 10005
#define lld long long

vector< vector< pair<int,int> > >adj(SIZE);
int depth[SIZE];
int tab[15][SIZE];
long long dist[15][SIZE];

void dfs(int to, int from, int _dist)
{
	depth[to]=depth[from]+1;
	tab[1][to]=from;
	dist[1][to]=_dist;
	for(auto x:adj[to])
	{
		if(x.first!=from)
			dfs(x.first,to,x.second);
	}
}

void process(int n)
{
	for(int i=2;i<15;i++)
	{
		for(int j=1;j<=n;j++)
		{
			tab[i][j]=tab[i-1][tab[i-1][j]];
			dist[i][j]=dist[i-1][tab[i-1][j]]+dist[i-1][j];
		}
	}
}

void pre(int root, int n)
{
	dfs(root,0,0);
	process(n);
}

pair<int,long long> lca(int u, int v)
{
	if(depth[u] > depth[v]) swap(u,v);

	long long d=0;
	
	if(depth[u] < depth[v])
	{
		int diff=depth[v]-depth[u];
		for(int i=13;i>=0;i--)
		{
			if(diff&(1<<i))
			{
				d+=dist[i+1][v];
				v=tab[i+1][v];
			}
		}
	}

	if(u==v) return {u,d};
	for(int i=14;i>=1;i--)
	{
		if(tab[i][u]!=tab[i][v])
		{
			d+=dist[i][u]+dist[i][v];
			u=tab[i][u];
			v=tab[i][v];
		}
	}
	d+=dist[1][u]+dist[1][v];
	return {tab[1][u],d};
}

int kth(int from, int to, int k)
{
	int l=depth[lca(from,to).first];

	int u=depth[from];
	int v=depth[to];

	if(u-l+1 >=k)
	{
		int diff=k-1;
		for(int i=13;i>=0;i--)
		{
			if(diff&(1<<i))
			{
				from=tab[i+1][from];
			}
		}
		return from;	
	}
	else
	{
		k-=(u-l);
		int diff=v-l-k+1;
		for(int i=13;i>=0;i--)
		{
			if(diff&(1<<i))
			{
				to=tab[i+1][to];
			}
		}
		return to;
	}
}

void solve()
{
	int n;
	cin>>n;
	adj.clear();
	adj.resize(n+1);
	memset(dist, 0 , sizeof dist);
	memset(tab, 0, sizeof tab);
	memset(depth, 0, sizeof depth);

	int x,y,z;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y>>z;
		adj[x].push_back({y,z});
		adj[y].push_back({x,z});
	}
	pre(1,n);
	string s;
	while(1)
	{
		cin>>s;
		if(s[1]=='O') break;
		else if(s[1]=='I')
		{
			cin>>x>>y;
			cout<<lca(x,y).second<<"\n";
		}
		else
		{
			cin>>x>>y>>z;
			cout<<kth(x,y,z)<<"\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;

	while(t--)
		solve();
}