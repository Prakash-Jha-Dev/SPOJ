#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int get(int x)
{
	int r=0,d;
	while(x)
	{
		d=x%10;
		x/=10;
		r+=(d*d);
	}
	return r;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	set<int>s;
	long long num,l=0;
	cin>>num;

	while(num!=1)
	{
		s.insert(num);
		l++;
		num = get(num);
		if(s.find(num) != s.end())
		{
			cout<<-1;
			exit(0);
		}
	}
	cout<<l;
}