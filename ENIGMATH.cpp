#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long long

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int test;
	cin>>test;
	lld n,m,g;

	while(test--)
	{
		cin>>n>>m;
		g = __gcd(n,m);
		n/=g;
		m/=g;
		cout<<m<<" "<<n<<"\n";
	}
}