#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int val,n,l,r,temp;
	cin>>n;
	long long c=0;

	map< int, pair<int,int> >data;

	data[1]=make_pair(n,0);
	data[n+1]=make_pair(n+1,0);

	while(n--)
	{
		cin>>val;
		auto it=data.lower_bound(val);
		if(it->first > val) it--;

		temp=it->second.second;
		l=it->first;
		r=(it->second).first;

		if(it!=data.end())

		data.erase(it);
		if(l!=r)
		{
			if(l<=val-1)
			data[l]=make_pair(val-1,temp+1);
			if(r>=val+1)
			data[val+1]=make_pair(r,temp+1);
		}
		c+=temp;
		cout<<c<<"\n";
	}
}