#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long long

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int test;
	cin>>test;
	lld n;
	string s;

	vector<string> v {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};

	while(test--)
	{
		map< string, int>ans;

		cin>>n>>s;
		for(int i=2;i<s.length();i++)
		{
			ans[s.substr(i-2,3)]++;
		}
		cout<<n<<" ";
		for(auto z:v) cout<<ans[z]<<" "; cout<<"\n";
	}
}