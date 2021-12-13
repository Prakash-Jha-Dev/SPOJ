#include <bits/stdc++.h>
using namespace std;
#define lld long long
vector<int64_t>tree(2*(2e5+5));
 
void build(int64_t n)
{
	for(int64_t i=n-1;i>0;--i)
		tree[i]=tree[i<<1]+tree[i<<1|1];
}
 
void modify(int64_t pos, int64_t val, int64_t n)
{
	pos+=n;
	for(tree[pos]=val; pos>1; pos>>=1)
	{
		tree[pos>>1]= (tree[pos] + tree[pos^1]);
	}
}
 
lld sum(int64_t l, int64_t r, int64_t n)
{
	lld ans=0;
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
	int n,nx,ex=100000;
	cin>>nx;
	n = nx + ex + 1;
	for(int i=ex+1;i<n;i++) cin>>tree[n+i];
	build(n);

	int shift = ex;

	int q,type,l,r;
	cin>>q;

	while(q--)
	{
		cin>>type;

		if(type == 1)
		{
			cin>>l>>r;
			l= l+shift;
			r= r+shift;
			cout<<sum(l,r,n)<<"\n";
		}
		else
		{
			cin>>l;
			modify(shift,l,n);
			shift--;
		}
	}
}