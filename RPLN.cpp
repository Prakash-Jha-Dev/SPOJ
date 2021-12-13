#include <bits/stdc++.h>
using namespace std;

vector<int64_t>tree(2*(1e5+1));
 
void build(int64_t n)
{
	for(int64_t i=n-1;i>0;--i)
		tree[i]=min(tree[i<<1],tree[i<<1|1]);
}
 
void modify(int64_t pos, int64_t val, int64_t n)
{
	pos+=n;
	for(tree[pos]=val; pos>1; pos>>=1)
	{
		tree[pos>>1]= min(tree[pos] , tree[pos^1]);
	}
}
 
int64_t sum(int64_t l, int64_t r, int64_t n)
{
	int64_t ans=1000000000;
	for(l+=n, r=r+n+1; l<r ; l>>=1, r>>=1)
	{
		if(l&1) {ans=min(ans,tree[l]);l++;}
		if(r&1) {--r;ans=min(ans,tree[r]);}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int test=1;test<=t;test++)
	{
		cout<<"Scenario #"<<test<<":\n";
		int n,q;
		cin>>n>>q;
		for(int i=n;i<(n+n);i++) cin>>tree[i];
		build(n);
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			if(l>r) swap(l,r);
			cout<<sum(l-1,r-1,n)<<"\n";
		}
	}
}