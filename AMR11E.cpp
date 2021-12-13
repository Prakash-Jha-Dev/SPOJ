#include <bits/stdc++.h>
using namespace std;

vector< int >fact(10001,0);
vector<int>sol;
void pre()
{
	for(int i=2;i<=10001;i++)
	{
		if(fact[i]>=3) sol.emplace_back(i);
		if(!fact[i])
		{
			for(int j=i;j<10001;j+=i)
			{
				fact[j]++;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	// cout<<sol.size()<<"\n";
	int t,x;
	cin>>t;
	while(t--)
	{
		cin>>x;
		cout<<sol[x-1]<<"\n";
	}
}