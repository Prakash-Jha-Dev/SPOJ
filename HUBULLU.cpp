#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int test;
	cin>>test;

	for(int kase=1; kase<=test; kase++)
	{
		long long n,k;
		cin>>n>>k;

		if(k==0) cout<<"Airborne wins.\n";
		else cout<<"Pagfloyd wins.\n";
	}
}