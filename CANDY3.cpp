#include <bits/stdc++.h>
using namespace std;
#define lld long long

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		long long n,s=0,x;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			s+=x;
			s%=n;
		}
		if(s%n==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
}