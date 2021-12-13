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
		int need,f;
		cin>>need>>f;

		vector<int>v(f);
		for(int i=0;i<f;i++) cin>>v[i];
		sort(v.rbegin(),v.rend());
		int i;
		for(i=0;i<f;i++)
		{
			need-=v[i];
			if(need<1) break;
		}
		i++;
		cout<<"Scenario #"<<kase<<":\n";
		if(i<=f) cout<<i<<"\n\n";
		else cout<<"impossible\n\n";
	}
}