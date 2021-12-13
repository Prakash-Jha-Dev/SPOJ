#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
	clock_t timer=clock();

	long long n;
	cin>>n;

	while(float(clock()-timer)/CLOCKS_PER_SEC <0.8 && n>1)
	{
		if(n%2 ==0) n/=2;
		else n=n*3+3;
	}

	if(n==1) cout<<"TAK";
	else cout<<"NIE";
}