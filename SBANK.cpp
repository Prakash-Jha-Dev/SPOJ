#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int test,n;
	string s,k;
	cin>>test;

	while(test--)
	{
		cin>>n;

		map< string, int > data;
		for(int i=0; i<n; i++)
		{
			s="";
			for(int j=0;j<6;j++)
			{
				cin>>k;
				s=s+k+" ";
			}
			data[s]++;
		}

		for(auto& x:data) cout<<x.first<<" "<<x.second<<"\n";
		cout<<"\n";
	}
}