#include <bits/stdc++.h>
using namespace std;

void dfs(int to, int from, auto& adj, auto& dist, int d)
{
	dist.push_back({d,to});
	for(auto x:adj[to])
	{
		if(x!=from)
		{
			dfs(x,to,adj,dist,d+1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x,y;
    cin>>n;
    vector< vector<int> >adj(n+1);
    for(int i=1;i<n;i++)
    {
    	cin>>x>>y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
    vector< pair<int,int> >dist;
    dfs(1,0,adj,dist, 0);
    auto it=*max_element(dist.begin(),dist.end());
    dist.clear();
    dfs(it.second,0,adj,dist,0);
    it=*max_element(dist.begin(),dist.end());
    cout<<it.first;
}