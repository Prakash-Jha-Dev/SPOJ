#include <bits/stdc++.h>
using namespace std;

vector<long long>sq;

void pre()
{
	for(long long int i=0;i<1000001;i++) sq.push_back(i*i);
		sort(sq.begin(),sq.end());
}

void solve()
{
	long long x;
	cin>>x;
	auto it=lower_bound(sq.begin(),sq.end(),x);
	long long m=0;
	bool flag=false;

	while(*it >= m)
	{
		auto bt=lower_bound(sq.begin(),sq.end(),x-*it);
		if(bt!=sq.end())
		{
			if(*bt==(x-*it))
			{
				flag=true;
				break;
			}
			else
				m=*bt;
		}
		else
			break;
		it--;
	}
	flag?cout<<"Yes\n":cout<<"No\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int t;
	cin>>t;
	while(t--)
	solve();
}