
#include <bits/stdc++.h>
using namespace std;
#define lld long long

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	while(1)
	{
		lld n,k;
		cin>>n>>k;

		if(n==-1 && k==-1) break;

		__int128 den = (n)*(n-1);
		__int128 num = 0;
		if(k&1) 
		{
			k/=2;
			num = k*k*2;
		}
		else
		{
			k = (k-2)/2;
			num = (k*(k+1))*2;
		}

		__int128 g=__gcd(num,den);
		num/=g;
		den/=g;

		if(den ==1 || num==0)
		{
			lld tn=num;
			cout<<tn<<"\n";
		}
		else
		{
			lld tn=num,td=den;
			cout<<tn<<"/"<<td<<"\n";
		}
	}
}