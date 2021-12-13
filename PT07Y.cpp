#include <bits/stdc++.h>
using namespace std;

void dfs(int to, int from, auto& adj, int& d)
{
	for(auto x:adj[to])
	{
		if(x!=from)
		{
			dfs(x,to,adj,++d);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    vector< vector<int> >adj(n+1);
    for(int i=0;i<m;i++)
    {
    	cin>>x>>y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
    if(m==n-1)
    {
    	int conn=1;
    	dfs(1,0,adj,conn);
    	if(conn==n)
    	{
    		cout<<"YES";
    		return 0;
    	}
    }
    cout<<"NO";
}