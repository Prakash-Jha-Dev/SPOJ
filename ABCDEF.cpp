#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;

	vector<long long>arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	long long ans=0;

	map< long long, int >s1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			s1[arr[i]+arr[j]]++;
		}
	}

	map< long long, int >sp1;
	for(auto x:s1)
	{
		for(auto y:arr)
		{
			if(y!=0)
			sp1[x.first*y]+=x.second;
		}
	}

	map< long long, int>p2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			p2[arr[i]*arr[j]]++;
		}
	}
	map<long long,int>sp2;
	for(auto x:p2)
	{
		for(auto y:arr)
		{
			sp2[x.first+y]+=x.second;
		}
	}

	for(auto x:sp1)
	{
		auto it=sp2.find(x.first);
		if(it!=sp2.end())
		{
			ans+=(x.second*(it->second));
		}
	}
	cout<<ans;
}