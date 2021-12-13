#include <bits/stdc++.h>
using namespace std;

vector< int >prime;
vector< bool >isprime(1300005);
void pre()
{
    prime.push_back(-1);
    for(int i=2; prime.size()<100005; i++)
    {
        if(!isprime[i])
        {
            prime.push_back(i);
            if(i < 1500)
            for(int j=i*i; j<1300005; j+=i) isprime[j] = 1;
        }
    }
}

vector<int>solve;
int size;
void dfs(int i, auto& adj, auto& vis)
{
    vis[i] = 1;
    size++;
    for(auto x:adj[i])
    {
        if(!vis[x])
        {
            dfs(x,adj,vis);
        }
    }
}

int main()
{
    pre();
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;

    while(t--)
    {
        int n,m,x,y;
        cin>>n>>m;

        vector< vector<int> >adj(n+1);

        while(m--)
        {
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        solve.clear();
        solve.push_back(0);
        vector<bool>vis(n+1,0);
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                size = 0;
                dfs(i,adj,vis);
                if(size > 1)
                solve.push_back(size);
            }
        }
        sort(solve.begin(),solve.end());
        cout<<prime[solve.back()]<<"\n";
    }
}