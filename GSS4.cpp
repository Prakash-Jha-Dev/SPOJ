#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define lld long long
lld tree[400005];
int root[200005];
void build(int n)
{
	for(int i=n-1;i>0;i--)
		tree[i]=(tree[i<<1]+tree[i<<1|1]);
}

void update(int pos, int val, int n)
{
	for(pos+=n; pos>1; pos>>=1)
		tree[pos>>1]=(tree[pos]+tree[pos^1]);
}

lld get(int l, int r, int n)
{
	lld ans=0;
	for(l+=n, r=r+n+1; l<r; l>>=1, r>>=1)
	{
		if(l&1) ans+=tree[l++];
		if(r&1) ans+=tree[--r];
	}
	return ans;
}

int find(int x)
{
	if(x!=root[x]) root[x]=find(root[x]);
	return root[x];
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int i=1;
	int n;
	// ifstream fin("in.txt");
	while(cin>>n)
	{
		root[n]=n;
		int q;
		for(int j=0;j<n;j++)
		{
			cin>>tree[n+j];
			root[j]=j;
		}
		build(n);

		cout<<"Case #"<<i++<<":\n";
		cin>>q;
		while(q--)
		{
			int x,l,r;
			cin>>x>>l>>r;
			if(l>r) swap(l,r);
			l--;r--;
			if(x==0)
			{
				for(int j=find(l); j<=r ; j=find(j+1))
				{
					tree[n+j]=sqrt(tree[n+j]);
					update(j,tree[n+j],n);
					if(tree[n+j]==1)
						root[j]=j+1;
				}
			}
			else
			{
				cout<<get(l,r,n)<<"\n";
			}
		}
		cout<<"\n";
	}
}