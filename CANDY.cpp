#include <bits/stdc++.h>
using namespace std;
#define lld long long

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(1)
	{
		int n,count=0;
		cin>>n;
		if(n==-1) break;

		long long x=0;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i],x+=arr[i];
		if(x%n !=0)
		{
			cout<<"-1\n";
		}
		else
		{
			x=x/n;
			for(int i=0;i<n;i++)
				if(arr[i]>x)
					count+=(arr[i]-x);
			cout<<count<<"\n";
		}
	}
}