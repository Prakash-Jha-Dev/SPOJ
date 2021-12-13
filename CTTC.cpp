#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,x;
	cin>>n;
	stack<int>s;
	vector< int >child(n+1,0);
	n+=n;

	s.push(0);
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x==s.top())
		{
			s.pop();
		}
		else
		{
			child[s.top()]++;
			s.push(x);
		}
	}
	n/=2;
	for(int i=1;i<=n;i++) cout<<i<<" -> "<<child[i]<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;

	for(int test=1;test<=t;test++)
	{
		cout<<"Case "<<test<<":\n";
		solve();
		cout<<"\n";
	}
}