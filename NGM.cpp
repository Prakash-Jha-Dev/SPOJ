#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n;
	cin>>n;

	if(n%10 !=0)
	{
		cout<<1<<"\n"<<n%10<<"\n";
	}
	else cout<<2;
}