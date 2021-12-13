#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long ncr(int n, int r)
{
	// cout<<n<<" "<<r<<"\n";
	if(r>n || n<0) return 0;
	if(r> n-r) r=n-r;

	__int128 ans = 1;
	for(int i = n-r+1; i<=n; i++)
	{
		ans*=i;
	}
	for(int i=2;i<=r;i++) ans/=i;

	return (long long)ans;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int test,n,r;
	cin>>test;

	while(test--)
	{
		cin>>r>>n;

		cout<<ncr(r-1,n-1)<<"\n";
	}
}