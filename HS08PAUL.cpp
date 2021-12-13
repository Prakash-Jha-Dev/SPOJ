#include <bits/stdc++.h>
using namespace std;
#define lld long long
#define SIZE 10001
vector<int>ans;

void pre(int n)
{	
	vector<bool>isprime(n+1,1);
	for(int i=2;i<=n;i++)
	{
		if(isprime[i] && i<3163)
		{
			for(int j=i*i;j<=n;j+=i) isprime[j]=0;
		}
	}

	for(int i=1;i<57;i++)
	{
		for(int k=1;k<3163;k++)
		{
			int j = i*i*i*i + k*k;
			if(j<10000001 && isprime[j])
			{
				ans.push_back(j);
			}
		}
	}
	sort(ans.begin(),ans.end());
	auto it = unique(ans.begin(),ans.end());
	ans.resize(distance(ans.begin(),it));
}

int main()
{
	// clock_t timer=clock();
	pre(10000000);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int test,n;
	cin>>test;
	while(test--)
	{
		cin>>n;
		auto it = upper_bound(ans.begin(),ans.end(),n);
		cout<<it-ans.begin()<<"\n";
	}
	// cout<<float(clock() - timer)/CLOCKS_PER_SEC<<"\n";
}