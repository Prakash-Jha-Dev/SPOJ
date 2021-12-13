#include <bits/stdc++.h>
using namespace std;
#define lld long long int
#define INF 100000001

class Graph
{
	int v;
	list < pair<int, int> > *adj;
	vector<int>dist;

public:
	Graph(int v)
	{
		this->v=v;
		adj=new list < pair<int, int> >[v+1];
	}

	void pre()
	{
		for(int i=1;i<=v;i++)
		{
			cout<<i<<":: ";
			for(auto x:adj[i])
			{
				cout<<"("<<x.second<<" "<<x.first<<") ";
			}
			cout<<"\n";
		}
	}
	void addEdge(int u, int v, int w)
	{
		adj[u].push_back(make_pair(w,v));
	}

	void solve(int source)
	{
		dist.resize(v+1);
		for(int i=1;i<=v;i++) dist[i]=INF;
		dist[source]=0;

		set< pair<int, int> >data;
		data.insert(make_pair(0,source));

		while(!data.empty())
		{
			int node=data.begin()->second;
			data.erase(data.begin());
			for(auto x:adj[node])
			{
				if((dist[node]+x.first)<dist[x.second])
				{
					dist[x.second]=dist[node]+x.first;
					data.insert(make_pair(dist[x.second],x.second));
				}
			}
		}
	}
	void display()
	{
		for(int i=1;i<=v;i++)
		{
			if(dist[i]<INF) cout<<i<<" "<<dist[i]<<"\n";
			else cout<<i<<" "<<"-1\n";
		}
	}
};

int main()
{
	lld N,Source ,D, C_1, C_2, D_1, D_2, W_1, W_2, W_3;
	cin>>N >>Source>> D>> C_1>> C_2>> D_1>> D_2>> W_1 >>W_2>> W_3;

	Graph g=Graph(N);
	for(lld i=1;i<=N;i++)
	{
		int deg=(i*C_2+i*i*D_2)%D;
		for(lld j=1;j<=deg;j++)
		{
			int y=(i*C_1 +j*D_1)%N;
			y++;
			int z=(i*W_1 +j*W_2)%W_3;
			g.addEdge(i,y,z);
		}
	}
	// g.pre();
	g.solve(Source);
	g.display();
}