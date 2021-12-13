#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	while(1)
	{
		int n;
		cin>>n;
		if(!n) break;
		vector<int>v(n+1);
		bool status = true;
		for(int i=1;i<=n;i++)
		{
			cin>>v[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(v[v[i]]!=i) status=0;
		}

		if(status) cout<<"ambiguous\n";
		else cout<<"not ambiguous\n";
	}
}