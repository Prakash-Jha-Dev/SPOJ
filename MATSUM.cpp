#include <bits/stdc++.h>
#define lld long long
using namespace std;

lld grid[1026][1026];
lld tree[1026][1026];

void modify(lld x,lld y1, lld val,lld n)
{
    for(;x<=n;x+=(x&(-x)))
        for(lld y=y1;y<=n;y+=(y&(-y)))
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
    while(t--)
    {
        lld n;
        cin>>n;
        memset(grid,0,(1026)*(1026)*sizeof(long long int));
        memset(tree,0,(1026)*(1026)*sizeof(long long int));
        string s="S";
        while(s[0]=='S')
        {
            cin>>s;

            if(s=="SET")
            {
                lld x,y,val;
                cin>>x>>y>>val;
                x++;y++;
                modify(x,y,val-grid[x][y],n);
                grid[x][y]=val;
            }
            else if(s=="SUM")
            {
                lld x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                x1++;x2++;y1++;y2++;
                cout<<(get(x2,y2)-get(x2,y1-1)-get(x1-1,y2)+get(x1-1,y1-1))<<"\n";
            }
        }
    }
}