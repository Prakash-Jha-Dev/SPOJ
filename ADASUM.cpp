#include <bits/stdc++.h>
using namespace std;
#define lld long long

int main()
{
	string s;
	cin>>s;

	lld rs = 1;
	lld rm = 1;
	lld ans = (s.back()-'0')*s.length();

	for(int i=s.length()-2;i>=0;i--)
	{
		rm = (rm*10)%1000000007;
		rs = (rs+rm)%1000000007;

		ans = (ans + ((i+1)*(s[i]-'0')*rs)%1000000007)%1000000007;
	}
	cout<<ans;
}