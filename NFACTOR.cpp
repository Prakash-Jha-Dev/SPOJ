#include <bits/stdc++.h>
using namespace std;
vector< vector<int> >ff(11);

void pre()
{
	ff[0].push_back(1);
	vector<int>f(1e6+1,0);
	for(int i=2;i<1000001;i++)
	{
		if(!f[i])
		{
			for(int j=i;j<1000001;j+=i) f[j]+=1;
		}
		ff[f[i]].push_back(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int test;
	cin>>test;
	int a,b,n;

	while(test--)
	{
		cin>>a>>b>>n;
		if(a>b) swap(a,b);
		auto it=upper_bound(ff[n].begin(),ff[n].end(),b);
		auto bt=upper_bound(ff[n].begin(),ff[n].end(),a-1);
		cout<< it-bt <<"\n";
	}
}