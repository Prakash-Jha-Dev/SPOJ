#include <bits/stdc++.h>
#include <fstream>
#define lld long long int
using namespace std;
#define MOD 1000000007

vector< lld >dsum(5e5+5,1);
void pre()
{
	for(int i=2; i<=500000;i++)
	{
		for(int j=i;j<=500000;j+=i)
		{
			dsum[j]+=i;
		}
	}
}

int main()
{
	pre();
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;
		cout<<dsum[n]-n<<"\n";
	}
}