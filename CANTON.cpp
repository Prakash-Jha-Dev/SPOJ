#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;

	vector<long long>val;
	long long x=0;
	int i=1;
	while(x<10000001)
	{
		val.push_back(x);
		x+=i;
		i++;
	}
	val.push_back(x);

	while(t--)
	{
		int term,z,num,den;
		cin>>term;
		int a=lower_bound(val.begin(),val.end(),term)-val.begin();

		if(a&1)
		{
			z=term-((a-1)*a)/2;
			num=a-(z-1);
			den=z;
		}
		else
		{
			z=term-((a-1)*a)/2;
			num=z;
			den=a-(z-1);
		}
		cout<<"TERM "<<term<<" IS "<<num<<"/"<<den<<"\n";
	}
}