#include <bits/stdc++.h>
using namespace std;
#define lld long long 
#define MOD 1000000007

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		list<int>ans;
		list<int>::iterator it,bt;

		for(int i=n;i>0;i--)
		{
			ans.push_front(i);
			int k = i%ans.size();
			it = ans.end();
			advance(it,-k);
			ans.splice(ans.end(),ans,ans.begin(),it);
		}
		for(auto x:ans) cout<<x<<" "; cout<<"\n";
	}
}