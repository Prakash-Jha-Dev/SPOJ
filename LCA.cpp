#include <bits/stdc++.h>
using namespace std;
#define SIZE 1005
#define level 12
#define lld int

vector< vector<int> >adj(SIZE);
int depth[SIZE];
int tab[11][SIZE];

void dfs(int to, int from)
{
	depth[to]=depth[from]+1;
	tab[1][to]=from;
	for(auto x:adj[to])
	{
		if(x!=from)
			dfs(x,to);
	}
}

void process(int n)
{
	for(int i=2;i<11;i++)
	{
		for(int j=1;j<=n;j++)
		{
			tab[i][j]=tab[i-1][tab[i-1][j]];
		}
	}
}

void pre(int root, int n)
{
	dfs(root,0);
	process(n);
}

int lca(int u, int v)
{
	if(depth[u] > depth[v]) swap(u,v);
	
	if(depth[u] < depth[v])
	{
		int diff=depth[v]-depth[u];
		for(int i=9;i>=0;i--)
		{
			if(diff&(1<<i))
				v=tab[i+1][v];
		}
	}

	if(u==v) return u;
	for(int i=10;i>=1;i--)
	{
		if(tab[i][u]!=tab[i][v])
		{
			u=tab[i][u];
			v=tab[i][v];
		}
	}
	return tab[1][u];
}

void fire()
{
	int n,x,y,child,query;
	cin>>n;
	for(int i=1;i<=n;i++) adj[i].clear();
	memset(depth,0,sizeof depth);
	memset(tab,0,sizeof tab); 
	for(int i=1;i<=n;i++)
	{
		cin>>child;
		for(int j=1;j<=child;j++)
		{
			cin>>x;
			adj[x].push_back(i);
			adj[i].push_back(x);
		}
	}
	pre(1,n);
	cin>>query;
	while(query--)
	{
		cin>>x>>y;
		cout<<lca(x,y)<<"\n";
	}
}

int main()
{
	int t;
	cin>>t;
	for(int test=1;test<=t;test++)
	{
		cout<<"Case "<<test<<":\n";
		fire();
	}
}