#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	while(1)
	{
		int n,m;
		cin>>n>>m;
		if(n==-1) break;

		if(n<m) swap(n,m);

		m++;
		cout<<int(ceil((n+0.0)/m))<<"\n";
	}
}