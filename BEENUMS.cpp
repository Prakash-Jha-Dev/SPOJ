#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	long long n;

	while(1)
	{
		cin>>n;
		if(n==-1) break;

		if(n==1) cout<<"Y\n";
		else 
		{
			n--;
			long long k = (-3+sqrt(9 + 12*n))/6;

			if(n%6==0 && k*(k+1)*3==n)
			{
				cout<<"Y\n";
			}
			else cout<<"N\n";
		}
	}
}