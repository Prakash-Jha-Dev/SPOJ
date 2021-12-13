#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(1)
	{
		int n;
		cin>>n;

		if(!n) break;
		vector< pair<int,int> >pt(n),slope;
		for(int i=0;i<n;i++) cin>>pt[i].first>>pt[i].second;
		sort(pt.begin(),pt.end());

		pair<int,int> temp;
		int g;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				temp.first=pt[j].first-pt[i].first;
				temp.second=pt[j].second-pt[i].second;

				g=__gcd(temp.first,temp.second);
				temp.first/=g;
				temp.second/=g;

				if(temp.first==0) 
				{
					temp.first=0;
					temp.second=1;
				}
				if(temp.second==0)
				{
					temp.first=0;
					temp.second=0;
				}
				slope.push_back(temp);
			}
		}
		sort(slope.begin(),slope.end());
		auto it=unique(slope.begin(),slope.end());
		cout<<it-slope.begin()<<"\n";
	}
}

