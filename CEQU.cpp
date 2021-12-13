#include <bits/stdc++.h>
using namespace std;
#define lld long long

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int test;
	cin>>test;
	lld a,b,c;
	for (int kase=1; kase<=test; kase++)
	{
		cin>>a>>b>>c;
		cout<<"Case "<<kase<<": ";
		if(c%__gcd(a,b)) cout<<"No\n";
		else cout<<"Yes\n";
	}

}