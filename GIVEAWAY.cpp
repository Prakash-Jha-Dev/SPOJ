#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
typedef tree< pair<int, int>,null_type,less<pair<int, int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ordered_set seg[2000005];
int arr[500005];

void merge(auto& it1, auto& it2, auto& it)
{
	for(auto x:it1)
		it.insert(x);
	for(auto x:it2)
		it.insert(x);
}

void build(int idx, int l, int r)
{
	if(l==r)
	{
		seg[idx].insert({arr[l],l});
		return;
	}
	int mid=(l+r)/2;
	build(idx*2, l ,mid);
	build(idx*2+1, mid+1, r);
	merge(seg[idx<<1], seg[idx<<1|1],seg[idx]);
}

int query(int idx, int l, int r, int beg, int end, int val)
{
	if(r<beg || l>end || l>r) return 0;
	if(beg<=l && r<=end)
	{
		auto it=seg[idx].order_of_key({val+1,0});
		return (seg[idx].size()-it);
	}
	return query(idx*2, l, (l+r)/2, beg, end, val)+query(idx*2+1,(l+r)/2 +1,r, beg, end, val);
}

void update(int idx, int l, int r,int pos, int val)
{
	
	if(l<=pos && pos<=r)
	{
		auto it=seg[idx].find({arr[pos],pos});
		seg[idx].erase(it);
		seg[idx].insert({val,pos});
		if(l!=r)
		{
			update(idx<<1, l, (l+r)/2, pos,val);
			update(idx<<1|1,(l+r)/2 +1,r, pos,val);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q,i,l,r,x;
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>arr[i];
	build(1,1,n);
	cin>>q;
	while(q--)
	{
		cin>>i;
		if(i==0)
		{
			cin>>l>>r>>x;
			cout<<query(1,1,n,l,r,x)<<"\n";
		}
		else
		{
			cin>>l>>x;
			update(1,1,n,l,x);
			arr[l]=x;
		}
	}
}