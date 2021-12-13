#include <bits/stdc++.h>
using namespace std;

vector<int>type,par;

int get_par(int i)
{
	if(par[i]==i) return i;
	int t2 = par[i];
	par[i] = get_par(par[i]);
	type[i] = (type[i] + type[t2])%3;
	return par[i];
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t,n,k,ans,a,b,c,pb,pc,tmp;
	cin>>t;

	while(t--)
	{
		cin>>n>>k;
		ans = 0;
		type.resize(n+1);
		par.resize(n+1);
		for(int i=1;i<=n;i++) par[i]=i,type[i]=0;

		for(int i=1;i<=k;i++)
		{
			cin>>a>>b>>c;

			if(b>n || c>n) 
			{
				ans++;
				continue;
			}

			pb = get_par(b);
			pc = get_par(c);

			if(pb == pc)
			{
				tmp = (type[b] - type[c] +3) % 3;
				if(tmp != a-1) ans++;
			}
			else
			{
				par[pb] = pc;
				tmp = (type[b] - type[c] -a +1)%3;
				type[pb] = tmp < 0? -tmp : -tmp+3;
			}
		}
		cout<<ans<<"\n";
	}
}