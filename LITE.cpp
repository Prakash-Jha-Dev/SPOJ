#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
	int on,lazy;
}pairs;

pairs tree[400005];

void lazier(int idx, int& l, int& r, int& beg, int& end)
{
	tree[idx].lazy^=1;
	if(l==r) return;

	int mid=(r+l)>>1;
	tree[idx<<1].on=(mid-l+1-tree[idx<<1].on);
	tree[idx<<1|1].on=(r-mid-tree[idx<<1|1].on);

	tree[idx<<1].lazy^=1;
	tree[idx<<1|1].lazy^=1;
}

void update(int idx, int l, int r, int& beg, int& end)
{
	if(l>end || r<beg) return;

	if(beg<=l && r<=end)
	{
		tree[idx].on=(r-l+1-tree[idx].on);
		tree[idx].lazy^=1;
		return;
	}
	if(tree[idx].lazy) lazier(idx,l,r,beg,end);
	int mid=(l+r)>>1;
	update(idx<<1, l, mid, beg, end);
	update(idx<<1|1, mid+1, r, beg, end);
	tree[idx].on=tree[idx<<1].on+tree[idx<<1|1].on;
}

int get(int idx, int l, int r, int& beg, int& end)
{
	if(l>end || r<beg) return 0;

	if(beg<=l && r<=end)	return tree[idx].on;
	if(tree[idx].lazy) lazier(idx,l,r,beg,end);

	int mid=(l+r)>>1;
	return get(idx<<1, l, mid, beg, end) + get(idx<<1|1, mid+1, r, beg, end);
}
 
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	while(q--)
	{
		int i,l,r;
		cin>>i>>l>>r;
		if(i==0)	update(1,1,n,l,r);
		else	cout<<get(1,1,n,l,r)<<"\n";
	}
}