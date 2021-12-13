#include <bits/stdc++.h>
using namespace std;

vector<string>v{"abcdef","bc","abdeg","abcdg","bcfg","acdfg","acdefg","abc","abcdefg","abcdfg"};

int main()
{
	int test;
	cin>>test;

	for(int i=1;i<=test;i++)
	{
		int n;
		cin>>n;

		cout<<"Case "<<i<<": "<<v[n]<<"\n";
	}
}