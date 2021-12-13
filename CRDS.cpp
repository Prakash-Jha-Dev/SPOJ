#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;

	while(t--)
	{
		long long n;
		cin>>n;

		n = (n*(n-1))/2 + (n*(n+1));
		cout<<n%1000007<<"\n";
	}
}