#include <bits/stdc++.h>
using namespace std;

map<string,int>city;

vector< list< pair<int, int> > >adj;
void edge(int u, int v, int w)
{
	adj[u].push_back({w,v});
	// adj[v].push_back(w,u);
}
int dj(int src, int dest, int n)
{
	vector< int >dist(n+1,99999999);
	vector< bool >vis(n+1,0);
	priority_queue< pair<int,int> , vector<pair<int,int> >, greater< pair<int,int> > >pq;
	dist[src]=0;
	pq.push({0,src});

	int count=1;

	while(!pq.empty())
	{
		int ver=pq.top().second;
		int wt=pq.top().first;
		pq.pop();
		if(ver==dest) break;
		if(vis[ver]) continue;
		vis[ver]=1;
		for(auto x:adj[ver])
		{
			if((wt+x.first)< dist[x.second])
			{
				dist[x.second]=wt+x.first;
				pq.push({dist[x.second],x.second});
			}
		}
	}
	return dist[dest];
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
    	adj.clear();
    	city.clear();
    	int n,p,v,w,query;
    	string s1,s2;
    	cin>>n;
    	adj.resize(n+1);

    	for(int i=1;i<=n;i++)
    	{
    		cin>>s1;
    		city[s1]=i;
    		cin>>p;
    		for(int j=0;j<p;j++)
    		{
    			cin>>v>>w;
    			edge(i,v,w);
    		}
    	}

    	cin>>query;
    	while(query--)
    	{
    		cin>>s1>>s2;
    		int src=city[s1];
    		int dest=city[s2];
    		cout<<dj(src,dest,n)<<"\n";
    	}
	}
}