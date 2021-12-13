#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int test;
	cin>>test;

	for(int kase=1;kase<=test;kase++)
	{
		int n,m,x;
		cin>>n>>m;

		int gg=0,gm=0;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			gg=max(gg,x);
		}
		for(int i=0;i<m;i++)
		{
			cin>>x;
			gm=max(gm,x);
		}

		if(gm>gg) cout<<"MechaGodzilla\n";
		else cout<<"Godzilla\n";
	}
}