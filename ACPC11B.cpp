#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long long

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int test;
	cin>>test;
	lld n,m;

	while(test--)
	{
		cin>>n;
		vector< int > v1(n);
		for(int i=0;i<n;i++) cin>>v1[i];
		cin>>m;
		vector< int > v2(m);	
		for(int i=0;i<m;i++) cin>>v2[i];

		sort(v2.begin(),v2.end());
		int mm=100000000;
		for(int i=0;i<n;i++)
		{
			auto it = lower_bound(v2.begin(),v2.end(),v1[i]);
			if(it!=v2.end()) mm=min(mm, abs(*it - v1[i]));

			if(it!=v2.begin())
			{
				it--;
				mm=min(mm, abs(*it - v1[i]));
			}
		}
		cout<<mm<<"\n";
	}
}