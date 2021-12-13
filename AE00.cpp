#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;

	vector<int>ans(100001,0);

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sqrt(i);j++)
		{
			if(i%j==0)
				ans[i]++;
		}
		ans[i]+=ans[i-1];
	}

	cout<<ans[n];
}