#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>ans(4,1);
	int temp;
	bool f=true;
	while(f)
	{
		f=false;
		for(int i=0;i<4;i++) cout<<ans[i]<<" "; cout<<"\n";
		for(int i=0;i<4;i++)
		{
			cin>>temp;
			if(temp!=1)
			{
				ans[i]++;
				f=true;
			}
		}
		fflush(stdout);
	}
}