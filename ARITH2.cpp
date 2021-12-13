#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define mod 1000000007

long long parse(string &s)
{
	istringstream is(s);
	long long ans;
	long long num;
	char op;

	is>>ans;
	while(!is.eof())
	{
		is>>op;
		if(op =='=') break;

		is>>num;
		if(op == '+') ans+=num;
		if(op == '-') ans-=num;
		if(op == '*') ans*=num;
		if(op == '/') ans/=num;
	}
	return ans;
}

int main()
{
	// ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int test;
	cin>>test;
	string s;

	while(test--)
	{
		getline(cin,s);
		// cout<<s<<"\n";
		if(s.back() != '=') {test++;continue;}
		cout<<parse(s)<<"\n";
	}
}