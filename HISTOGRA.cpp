#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(1)
	{
		long long n;
		cin>>n;
		if(n==0) break;

		vector<long long>arr(n+2,0);
		for(long long i=1;i<=n;i++) cin>>arr[i];
		long long ans=0;
		stack<long long>bar;
		bar.push(0);
		for(long long i=1;i<=n+1;i++)
		{
			long long k=i;
			while(arr[i]<arr[bar.top()])
			{
				ans=max(ans, (i-bar.top())*arr[bar.top()]);
				k=bar.top();
				bar.pop();
			}
			bar.push(k);
			arr[k]=arr[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}