#include <bits/stdc++.h>
using namespace std;

int tree[300000];

void upd(int pos, int n)
{
	while(pos<=n)
	{
		tree[pos]+=1;
		pos+=(pos&(-pos));
	}
}

int get(int idx)
{
	int ans=0;
	while(idx)
	{
		ans+=tree[idx];
		idx=(idx&(idx-1));
	}
	return ans;
}

void build(int n)
{
	for(int i=1;i<=n;i++) tree[i]=0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		build(n+1);
		
		int ans = 0;
		map<string,int>chk;
		vector<string>v1(n);
		string s;

		for(int i=0;i<n;i++) 
		{
			cin>>v1[i];
			chk[v1[i]]=i+1;
		}
		for(int i=0;i<n;i++) 
		{
			cin>>s;
			ans+=get(chk[s]);
			upd(chk[s],n+1);
		}
		ans = n*(n-1)/2 - ans;
		cout<<ans<<"\n";
	}
}
