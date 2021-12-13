#include <bits/stdc++.h>
#include <fstream>
#define lld long long int
using namespace std;
#define MOD 1000000007

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;

	while(t--)
	{
		int n,k;
		cin>>n>>k;

		n--;
		bitset<32>temp(n);
		int r=k - __builtin_popcount(n);
		if(r >= 0) cout<<n<<"\n";
		else if(k==0) cout<<-1<<"\n";
		else 
		{
			while(__builtin_popcount(n) > k)
			{
				n--;
				n=(n&(n-1));
				n++;
			}
			cout<<n<<"\n";
		}
	}
}