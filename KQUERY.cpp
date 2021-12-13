#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int val, l, r, idx;
} type;

bool comp(type&t1, type&t2)
{
    if(t1.val == t2.val) return t1.l>t2.l;
    return t1.val > t2.val;
}

int ans[200001];
vector<int>tree(2*(30005));
type arr[230001];

void modify(int pos, int n)
{
    pos+=n;
    for(tree[pos]+=1; pos>1; pos>>=1)
    {
        tree[pos>>1]= (tree[pos] + tree[pos^1]);
    }
}
 
int sum(int l, int r, int n)
{
    int ans=0;
    for(l+=n, r=r+n+1; l<r ; l>>=1, r>>=1)
    {
        if(l&1) ans+=tree[l++];
        if(r&1) ans+=tree[--r];
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].val;
        arr[i].l=arr[i].r=0;
        arr[i].idx=i+1;
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>arr[n+i].l>>arr[n+i].r>>arr[n+i].val;
        arr[n+i].idx=i;
    }
    sort(arr,arr+n+q,comp);
    for(int i=0;i<n+q;i++)
    {
        if(arr[i].l==0)
        {
            modify(arr[i].idx,30005);
        }
        else
        {
            ans[arr[i].idx]=sum(arr[i].l,arr[i].r,30005);
        }
    }
    for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
}