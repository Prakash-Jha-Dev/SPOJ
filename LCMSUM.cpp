#include <bits/stdc++.h>
using namespace std;

vector<long long int>phi(1000001),val(1000001,0);
void pre()
{
	for(int i=1;i<1000001;i++) phi[i]=i;
	for(int i=2;i<1000001;i++)
	{
		if(phi[i]==i)
		{
			for(int j=i;j<1000001;j+=i)
				phi[j]-=(phi[j]/i);
		}
	}

	for(int i=1;i<1000001;i++)
	{
		for(int j=i;j<1000001;j+=i)
		{
			val[j]+=(i*phi[i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<((val[n]+1)*(n)/2)<<"\n";
	}
}