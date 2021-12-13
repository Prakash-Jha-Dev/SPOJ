#include <bits/stdc++.h>
using namespace std;

vector<int>tree(2*(50000+1));
void build(int n)
{
	for(int i=n-1;i>0;--i)
		tree[i]=max(tree[i<<1],tree[i<<1|1]);
}
 
int get(int l, int r, int n)
{
	int ans=0;
	for(l+=n, r=r+n; l<r ; l>>=1, r>>=1)
	{
		if(l&1) ans=max(ans,tree[l++]);
		if(r&1) ans=max(ans,tree[--r]);
	}
	return ans;
}

int main()
{
	int n,q,count=0;
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>tree[n+i];
	build(n);
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		l--;r--;
		if(tree[n+l]>=get(l,r,n)) count++;
	}
	cout<<count;
}