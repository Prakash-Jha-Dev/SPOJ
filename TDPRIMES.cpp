#include <bits/stdc++.h>
using namespace std;

vector<bool>isprime(100000001,1);
void pre()
{
	int count=0;
	for(int i=2;i<100000001;i++)
	{
		if(isprime[i])
		{
			count++;
			if(count%100==1) cout<<i<<"\n";
			if(i<10001)
			{
				for(int j=i*i;j<100000001;j+=i)
					isprime[j]=0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
}