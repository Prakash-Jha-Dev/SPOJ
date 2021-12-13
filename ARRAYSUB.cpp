#include <bits/stdc++.h>
using namespace std;

vector<int64_t>tree(2*(1e5+1));
 
void build(int64_t n)
{
	for(int64_t i=n-1;i>0;--i)
		tree[i]=max(tree[i<<1],tree[i<<1|1]);
}

int64_t get(int64_t l, int64_t r, int64_t n)
{
	int64_t ans=0;
	for(l+=n, r=r+n+1; l<r ; l>>=1, r>>=1)
	{
		if(l&1) {ans=max(ans,tree[l]);l++;}
		if(r&1) {--r;ans=max(ans,tree[r]);}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n;
	for(int i=n;i<n+n;i++) cin>>tree[i];
	build(n);
	cin>>m;
	for(int i=m-1;i<n;i++)
		cout<<get(i-m+1,i,n)<<" ";
}