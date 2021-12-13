#include <bits/stdc++.h>
using namespace std;

vector< long long >sum_div(1000001,1);

void pre()
{
	sum_div[1]=0;
	for(int i=2;i<1000001;i++)
		for(int j=i+i;j<1000001;j+=i)
			sum_div[j]+=i;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int t;
	cin>>t;

	while(t--)
	{
		int x,y;
		cin>>x>>y;
		if(sum_div[x]==y && sum_div[y]==x)
			cout<<"Friendship is ideal\n";
		else
			cout<<"Friendship is not ideal\n";
	}
}