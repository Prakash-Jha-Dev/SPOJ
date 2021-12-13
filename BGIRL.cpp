#include <bits/stdc++.h>
#include <ctime>
using namespace std;

typedef struct 
{
    int par;
    int size;
}data;

vector< data >arr;
void build(int n)
{
    arr.resize(n+1);
    for(int i=0; i<=n; i++)
    {
        arr[i].par = i;
        arr[i].size = 1;
    }
}

int get(int x)
{
    if(x != arr[x].par)
    {
        arr[x].par = get(arr[x].par);
    }
    return arr[x].par;
}

void combine(int u, int v)
{
    // cout<<u<<" "<<v<<" :: ";
    u = get(u);
    v = get(v);
    // cout<<u<<" "<<v<<"\n";
    if(u == v) return;

    if(arr[u].size < arr[v].size) swap(u,v);
    arr[v].par = u;
    arr[u].size += arr[v].size;
}

vector<bool>isprime(100001,1);
void pre()
{
    isprime[0] = isprime[1] = 0;
    for(int i=2; i<100001; i++)
    {
        if(isprime[i])
        {
            if(i < 400)
            for(int j=i*i; j<100001; j+=i) isprime[j]=0;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int t;
    cin>>t;

    while(t--)
    {
        int n,m,x,y;
        cin>>n>>m;

        build(n);
        for(int i=0; i<m; i++)
        {
            cin>>x>>y;
            combine(x,y);
            // display(n);
        }

        int ans = -1;
        for(int i=1; i<=n; i++)
        {
            if(i == arr[i].par && isprime[arr[i].size])
            {
                ans = max(ans, arr[i].size);
            }
        }
        cout<<ans<<"\n";
    }
}