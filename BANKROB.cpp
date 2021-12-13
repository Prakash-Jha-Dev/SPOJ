#include <bits/stdc++.h>
using namespace std;
#define INF 1000000

vector< int >par;
vector< vector<int> >adj,cap;

int bfs(int src, int dest)
{
	fill(par.begin(),par.end(),-1);
	par[src]=-2;

	queue< pair<int,int> >q;
	q.push({src,INF});

	int cur,val,nval;
	while(!q.empty())
	{
		cur = q.front().first;
		val = q.front().second;
		q.pop();
		// cout<<"curr: "<<cur<<"\n";
		for(auto x:adj[cur])
		{
			if(par[x]==-1 && cap[cur][x]>0)
			{
				par[x]=cur;
				nval = min(val, cap[cur][x]);

				if(x==dest) return nval;

				q.push({x,nval});
			}
		}
	}
	return 0;
}

int maxflow(int src, int dest)
{
	int flow = 0;
	int newflow;

	while(newflow = bfs(src,dest))
	{
		// cout<<newflow<<"\t newflow \n";
		flow += newflow;
		for(int i=dest; i!=src; i=par[i])
		{
			// cout<<"par:"<<par[i]<<" idx:"<<i<<"\n";
			cap[par[i]][i] -= newflow;
			cap[i][par[i]] += newflow;
		}
	}
	return flow;
} 

void input(int ver, int edges)
{
	ver<<=1;
	par.resize(ver+1);
	adj.resize(ver+1);
	cap.resize(ver+1);
	for(int i=1;i<=ver;i++) cap[i].resize(ver+1);

	int from,to,weight=INF;
	for(int i=1; i<=edges; i++)
	{
		cin>>from>>to;
		cap[from*2][to*2 -1] = weight;
		cap[to*2][from*2 -1] = weight;
		adj[from*2].push_back(to*2 -1);
		adj[to*2].push_back(from*2 -1);
		adj[to*2-1].push_back(from*2);
		adj[from*2-1].push_back(to*2);
	}

	for(int i=1; i<ver; i+=2)
	{
		cap[i][i+1] = cap[i+1][i] = 1;
		adj[i].push_back(i+1);
		adj[i+1].push_back(i);
	}

	// for(int i=1;i<=ver;i++)
	// {
	// 	cout<<i<<" :: ";
	// 	for(auto x:adj[i]) cout<<x<<" "; cout<<"\n";
	// }
}

int main()
{
	int n,m,src,dest;
	cin>>n>>m;
	cin>>src>>dest;

	input(n,m);
	cap[src*2-1][src*2] = cap[src*2][src*2 -1] = cap[dest*2-1][dest*2] = cap[dest*2][dest*2-1]=INF;
	cout<<maxflow(src*2-1,dest*2);
}