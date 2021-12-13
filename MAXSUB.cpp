#include <bits/stdc++.h>
using namespace std;

long long scount(int c)
{
	long long ans = 1;
	while(c--) ans=(ans*2)%1000000009;
	return ans;
}

int main() 
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		long long x,sum=0;
		
		map<long long, int>data;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			if(x>0) 
			{
				sum += x;
			}
			data[x]++;
		}
		
		if(sum>0) cout<<sum<<" "<<scount(data[0])<<"\n";
		else if(data.rbegin()->first == 0) cout<<0<<" "<<(scount(data[0])+1000000008)%1000000009<<"\n";
		else cout<<data.rbegin()->first<<" "<<data.rbegin()->second<<"\n";
	}
	return 0;
}