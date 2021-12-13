#include <bits/stdc++.h>
using namespace std;
#define ret pair<int, pair<int,int> >

string s;
int open[1200005],close[1200005],ans[1200005];

void build(int idx, int l, int r)
{
    if(l>r) return;
    if(l==r)
    {
        if(s[l]=='(')
        {
            open[idx]=1;
        }
        else
        {
            close[idx]=1;
        }
        return;
    }
    int left=idx<<1;
    int right=idx<<1|1;
    int mid=(l+r)>>1;

    build(left, l,mid);
    build(right , mid+1 , r);
    int minc=min(open[left] ,  close[right]);
    ans[idx]=ans[left]+ans[right]+(minc<<1);
    open[idx]=open[left]+open[right]-minc;
    close[idx]=close[left]+close[right]-minc;
}

void modify(int idx, int l, int r, int pos)
{
	if(pos>r || pos<l) return;
	if(l==r && l==pos)
	{
		if(s[l]=='(')
		{
			close[idx]=0;
			open[idx]=1;
		}
		else
		{
			open[idx]=0;
			close[idx]=1;
		}
		return;
	}
	int left=idx<<1;
    int right=idx<<1|1;
    int mid=(l+r)>>1;

    modify(left, l,mid, pos);
    modify(right , mid+1 , r, pos);
    int minc=min(open[left] ,  close[right]);
    ans[idx]=ans[left]+ans[right]+(minc<<1);
    open[idx]=open[left]+open[right]-minc;
    close[idx]=close[left]+close[right]-minc;
}

ret query(int idx, int l, int r, int beg, int end)
{
    if(end<l || beg>r)
        return {0,{0,0}};
    if(l<=beg && end<=r)
        return {ans[idx],{open[idx],close[idx]}};
    ret lret,rret;
    int mid=(beg+end)>>1;
    lret=query(idx<<1,l,r, beg, mid);
    rret=query(idx<<1|1 ,l,r, mid+1 , end);

    int minc=min(lret.second.first ,  rret.second.second);
    return {lret.first+rret.first+(minc<<1), { lret.second.first +rret.second.first-minc , lret.second.second +rret.second.second -minc}};
}
int main(void) 
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    for(int i=1;i<=10;i++)
    {
    	cout<<"Test "<<i<<":\n";
    	memset(open,0,sizeof open);
    	memset(close,0,sizeof close);
    	memset(ans,0,sizeof ans);
    	int n;
    	cin>>n;
	    cin>>s;
	    build(1,0,n-1);
	    int q,k;
	    cin>>q;
	    while(q--)
	    {
	        cin>>k;
	        if(k==0)
	        {
	        	ret x=query(1,0,n-1,0,n-1);
	        	if(x.first==n) cout<<"YES\n";
	        	else cout<<"NO\n";
	        }
	        else
	        {
	        	s[k-1]=(s[k-1]==')'?'(':')');
	        	modify(1,0,n-1,k-1);
	        }
	    }
    }
}