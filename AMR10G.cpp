#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;

	while(t--)
	{
		int n,k;
		cin>>n>>k;

		vector<int>v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		sort(v.begin(),v.end());

		int ans= 1000000000;
		for(int i=k-1;i<n;i++)
		{
			ans = min(ans,v[i]-v[i-k+1]);
		}
		cout<<ans<<"\n";
	}
}