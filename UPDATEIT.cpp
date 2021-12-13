#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,q,x,y,z;
		cin>>n>>q;
		std::vector<int> v(n+1,0);
		for(int i=0;i<q;i++)
		{
			cin>>x>>y>>z;
			v[x]+=z;
			v[y+1]-=z;
		}
		for(int i=1;i<=n;i++) v[i]+=v[i-1];
		cin>>q;
		while(q--)
		{
			cin>>x;
			cout<<v[x]<<"\n";
		}
	}
}