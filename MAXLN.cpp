#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

double get(double a, double r)
{
	return a*a + pow(4*r*r - a*a, 0.5);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int test;
	cin>>test;

	for(int kase=1; kase<=test; kase++)
	{
		double r,m,v1,v2,ex=0.00000001;
		cin>>r;

		double l = 0;
		double h = 2*r;

		int cnt = 200;
		while(cnt--)
		{
			m=(l+h)/2;
			v1=get(m,r);
			v2=get(m+ex,r);
			if(v1 < v2) l = m;
			else if(v1 > v2)	h = m;
			else if(v1 == v2) break;
			// cout<<fixed<<setprecision(10)<<v1<<" "<<v2<<" "<<l<<" "<<r<<"\n";
		}
		cout<<"Case "<<kase<<": "<<fixed<<setprecision(2)<<get(l,r)<<"\n";
	}
}