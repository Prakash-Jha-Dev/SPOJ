#include <bits/stdc++.h>
using namespace std;

vector<int>phi(1000001);
void pre()
{
	for(int i=1;i<=1000000;i++) phi[i]=i;
	for(int i=2;i<=1000000;i++)
	{
		if(phi[i]==i)
		{
			phi[i]-=1;
			for(int j=i+i;j<1000001;j+=i)
			{
				phi[j]-=(phi[j]/i);
			}
		}
	}
}

int main()
{
	pre();
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test,n;
    cin>>test;
    while(test--)
    {
    	cin>>n;
    	cout<<phi[n]<<"\n";
	}
}