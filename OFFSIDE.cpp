#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	while(1)
	{
		int a,d,x;
		cin>>a>>d;

		if(a==0) break;

		int am=10000,dm1=10000,dm2=10000;
		for(int i=0;i<a;i++)
		{
			cin>>x;
			am=min(am,x);
		}
		for(int i=0;i<d;i++)
		{
			cin>>x;

			if(x<=dm1)
			{
				dm2=dm1;
				dm1=x;
			}
			else if(x<dm2) dm2=x;
		}

		if(am < dm2) cout<<"Y\n";
		else cout<<"N\n";
	}
}