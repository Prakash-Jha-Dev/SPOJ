#include <bits/stdc++.h>
using namespace std;

map<long long, long long>data;

long long solve(long long n)
{
	if(n==0) return 0;
	if(data[n]) return data[n];
	else
	{
		data[n]=max(n,solve(n/2)+solve(n/3)+solve(n/4));
		return data[n];
	}
}

int main()
{
	int n;
	while(cin>>n)
	{
		cout<<solve(n)<<"\n";
	}
}