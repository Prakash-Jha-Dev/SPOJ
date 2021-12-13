#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
	int r[3];
	int lazy;
}node;

node tree[400005];

void shift(node& x)
{
	int temp=x.r[2];
	x.r[2]=x.r[1];
	x.r[1]=x.r[0];
	x.r[0]=temp;
	x.lazy++;
}

void build(int idx, int l, int r)
{
	if(l==r) 
	{
		tree[idx].r[0]=1;
		tree[idx].r[1]=tree[idx].r[2]=tree[idx].lazy=0;
		return;
	}
	int mid=(l+r)>>1;
	build(idx<<1, l, mid);
	build(idx<<1|1, mid+1, r);
	tree[idx].r[0]=r-l+1;
}

void lazier(int idx, int l, int r)
{
	if(l!=r)
	{
		tree[idx].lazy%=3;
		for(int i=0;i<tree[idx].lazy;i++)
		{
			shift(tree[idx<<1]);shift(tree[idx<<1|1]);
		}
	}
	tree[idx].lazy=0;
}

void update(int idx, int l, int r, int beg, int end)
{
	if(l>end || r<beg ) return;

	if(tree[idx].lazy) lazier(idx,l,r);

	if(beg<=l && r<=end)
	{
		shift(tree[idx]);
		return;
	}
	int mid=(l+r)>>1;
	update(idx<<1, l, mid, beg, end);
	update(idx<<1|1, mid+1, r, beg, end);

	for(int i=0;i<=2;i++)
	tree[idx].r[i]=tree[idx<<1].r[i]+tree[idx<<1|1].r[i];
}

int get(int idx, int l, int r, int beg, int end)
{
	if(l>end || r<beg ) return 0;

	if(tree[idx].lazy) lazier(idx,l,r);

	if(beg<=l && r<=end)	return tree[idx].r[0];
	int mid=(l+r)>>1;
	return get(idx<<1,l,mid,beg,end) + get(idx<<1|1,mid+1,r,beg,end);
}

void solve()
{
	int n,q,i,l,r;
	cin>>n>>q;
	build(1,0,n-1);
	while(q--)
	{
		cin>>i>>l>>r;
		if(l>r) swap(l,r);
		if(i==0) update(1,0,n-1,l,r);
		else cout<<get(1,0,n-1,l,r)<<"\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}