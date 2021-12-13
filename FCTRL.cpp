#include <bits/stdc++.h>
using namespace std;
#define lld long long int

void solve()
{
	lld n;
	cin>>n;
	lld ans=0;
	lld div=5;
	while(div<=n)
	{
		ans+=(n/div);
		div*=5;
	}
	cout<<ans<<"\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}