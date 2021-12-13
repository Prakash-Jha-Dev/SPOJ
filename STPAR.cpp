#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(1)
	{
		int n;
		cin>>n;
		if(n==0) return 0;

		vector<int>arr(n+1);
		for(int i=1;i<=n;i++) cin>>arr[i];

		stack<int>s1,s2;
		int req=1;
		for(int i=1;i<=n;i++)
		{
			if(arr[i]!=req)
			{
				s2.push(arr[i]);
			}
			else
			{
				s1.push(arr[i]);
				req++;
				while(!s2.empty() && s2.top()==req)
				{
					s1.push(s2.top());
					s2.pop();
					req++;
				}
			}
		}

		while(!s2.empty() && s2.top()==req)
		{
			s1.push(s2.top());
			s2.pop();
			req++;
		}
		req!=n+1?cout<<"no\n":cout<<"yes\n";
	}
}