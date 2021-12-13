#include <bits/stdc++.h>
using namespace std;

vector< list< pair<int, int> > >adj;
void edge(int u, int v, int w)
{
	adj[u].push_back({w,v});
	// adj[v].push_back(w,u);
}
int dj(int src, int t, int n)
{
	vector< int >dist(n+1,99999999);
	priority_queue< pair<int,int> , vector<pair<int,int> >, greater< pair<int,int> > >pq;
	dist[src]=0;
	pq.push({0,src});

	while(!pq.empty())
	{
		int ver=pq.top().second;
		int wt=pq.top().first;
		pq.pop();
		for(auto x:adj[ver])
		{
			if((wt+x.first)< dist[x.second])
			{
				dist[x.second]=wt+x.first;
				pq.push({dist[x.second],x.second});
			}
		}
	}
	int count=0;
	for(int i=1;i<=n;i++) if(dist[i]<=t) count++;
	cout<<count;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,src,t,e,x,y,z;
	cin>>n>>src>>t>>e;
	adj.resize(n+1);
	for(int i=0;i<e;i++)
	{
		cin>>x>>y>>z;
		if(x==y) continue;
		edge(y,x,z);
	}
	dj(src,t,n);
}