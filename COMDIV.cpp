#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long long

vector< int >divi(1000001,1);
void pre()
{
	for(int i=2;i<1000001;i++)
	{
		for(int j=i;j<1000001;j+=i) divi[j]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();

	int test;
	cin>>test;
	lld n,m;

	while(test--)
	{
		cin>>n>>m;
		cout<<divi[__gcd(n,m)]<<"\n";
	}
}