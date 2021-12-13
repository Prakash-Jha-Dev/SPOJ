#include <bits/stdc++.h>
using namespace std;

vector<bool>isprime(1e8+1,1);
vector<int>pix(1e8);
void pre()
{
	isprime[0]=isprime[1]=0;
	for(int i=2;i<=100000000;i++)
	{
		if(isprime[i])
		{
			if(i<10001)
			for(int j=i*i;j<100000001;j+=i)
			{
				isprime[j]=0;
			}
		}
		pix[i]=pix[i-1]+isprime[i];
	}
}

int main()
{
	pre();
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(1)
	{
		int n;
		cin>>n;
		if(!n) break;
		double ans=pix[n]-n/log(n);
		ans=abs(ans/pix[n]*100);
		printf("%.1lf\n",ans);
	}
}