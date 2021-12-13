#include <bits/stdc++.h>
#define lld long long
using namespace std;

lld tree[1026][1026];
void modify(lld x,lld y1, lld val,lld n,lld m)
{
    for(;x<=n;x+=(x&(-x)))
        for(lld y=y1;y<=m;y+=(y&(-y)))
            tree[x][y]+=val;
}

lld get(lld x, lld y1)
{
    lld ans=0;
    for(;x>0;x-=(x&-x))
        for(lld y=y1; y>0; y-=(y&-y))
            ans+=tree[x][y];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        lld n,m,k,sol=0;
        cin>>n>>m>>k;
        memset(tree,0,(1026)*(1026)*sizeof(long long int));
        while(k--)
        {
            lld x,y;
            cin>>x>>y;
            sol+=(get(x-1,m)-get(x-1,y) +get(n,y-1)-get(x,y-1));
            modify(x,y,1,n,m);
        }
        cout<<"Test case "<<i<<": "<<sol<<"\n";
    }
}