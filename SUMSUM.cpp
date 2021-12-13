#include <bits/stdc++.h>
using namespace std;
#define lld long long

int tree[29][200005];

inline void update(int bit_lev, int idx, int val, int n)
{
	for(tree[bit_lev][idx+=n]=val; idx>1; idx>>=1) tree[bit_lev][idx>>1] = tree[bit_lev][idx]+tree[bit_lev][idx^1];
}

inline int get(int bit_lev, int l, int r, int n)
{
	int ans=0;
	for(l+=n, r=r+n+1; l<r; l>>=1, r>>=1)
	{
		if(l&1) ans+=tree[bit_lev][l++];
		if(r&1) ans+=tree[bit_lev][--r];
	}
	return ans;
}

inline void setter(int idx, int val, int n)
{
	for(int i=0;i<28;i++)
	{
		if(val&(1<<i)) update(i,idx,1,n);
		else update(i,idx,0,n);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	lld n,q,type,x,y;
	string op;
	cin>>n>>q;

	for(int i = 0; i < n; ++i)
	{
		cin>>x;
		setter(i,x,n);
	}

	while(q--)
	{
		cin>>type;

		if(type == 1)
		{
			cin>>x>>y;
			setter(y-1,x,n);
		}
		else
		{
			cin>>op>>x>>y;
			x--;y--;
			long long ans =0, temp;
			if(op[0]=='A')
			{
				for(lld i=0;i<28;i++)
				{
					temp  = get(i,x,y,n);
					ans = ans + ((temp*(temp-1)/2)*(1LL<<i));
				}
			}
			else if(op[0]=='O')
			{
				for(lld i=0;i<28;i++)
				{
					temp  = get(i,x,y,n);
					ans = ans + ((((y-x+1)*(y-x)/2) - ((y-x+1-temp)*(y-x-temp)/2))*(1<<i));
				}
			}
			else
			{
				for(lld i=0;i<28;i++)
				{
					temp  = get(i,x,y,n);
					ans = ans + (temp*(y-x+1-temp))*(1<<i);
				}
			}
			cout<<ans<<"\n";
		}
	}
}