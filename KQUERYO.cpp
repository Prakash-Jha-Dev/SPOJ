#include<bits/stdc++.h>
using namespace std;

vector<int>tree[120005];
int arr[30005];

void build(int idx, int l, int r)
{
	if(l==r)
	{
		tree[idx].push_back(arr[l]);
		return;
	}
	int mid=(l+r)/2;
	build(idx*2, l ,mid);
	build(idx*2+1, mid+1, r);
	merge(tree[idx*2].begin(),tree[idx*2].end(), tree[idx*2+1].begin(), tree[idx*2+1].end(), back_inserter(tree[idx]));
}

int query(int idx, int l, int r, int beg, int end, int val)
{
	if(r<beg || l>end || l>r) return 0;
	if(beg<=l && r<=end)
	{
		auto it =upper_bound(tree[idx].begin(), tree[idx].end(), val);
		return (tree[idx].end()-it);
	}
	return query(idx*2, l, (l+r)/2, beg, end, val)+query(idx*2+1,(l+r)/2 +1,r, beg, end, val);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q,l,r,x,i,j,k,last=0;
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>arr[i];
	build(1,1,n);
	cin>>q;
	while(q--)
	{
		cin>>l>>r>>x;
		i=l^last, j=r^last, k=x^last;

		if(i<1) i=1;
		if(j>n) j=n;
		if(i>j)	last=0;
		else	last=query(1,1,n,i,j,k);
		cout<<last<<"\n";
	}
}