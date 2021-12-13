#include <bits/stdc++.h>
using namespace std;

vector< int >fact(10000001,0);
vector< long long >ans(10000001,0);
void pre()
{
	for(int i=2;i<10000001;i++) fact[i]=i;
	int sq=sqrt(10000001);
	for(int i=2;i<=sq;i++)
	{
		if(fact[i]==i)
		{
			for(int j=i+i;j<10000001;j+=i)
			{
				if(fact[j]==j) fact[j]=i;
			}
		}
	}
	for(int i=2;i<10000000;i++)
		ans[i]=ans[i-1]+fact[i];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();

	int t,x;
	cin>>t;
	while(t--)
	{
		cin>>x;
		cout<<ans[x]<<"\n";
	}
}