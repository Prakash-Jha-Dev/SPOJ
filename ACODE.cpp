#include <bits/stdc++.h>
using namespace std;

map<string, long long>data;

long long solve(string s)
{
	if(data.count(s)>0) return data[s];
	long long temp = solve(s.substr(1,s.length()-1));
	data[s.substr(1,s.length()-1)]=temp;
	if(s[1]=='0') data[s.substr(1)]=0;

	if(s[0]=='0')
	{
		data[s]=0;
	}

	if(s.length()>2 && s[0]=='1')
	{
		return data[s.substr(1,s.length()-1)]+data[s.substr(2,s.length()-2)];
	}
	else if(s.length()>2 && s[0]=='2' && s[1]<='6')
	{
		return data[s.substr(1,s.length()-1)]+data[s.substr(2,s.length()-2)];
	}
	else if(s.length()>1)
	{
		return data[s.substr(1,s.length()-1)];
	}
}

int main()
{
	string s;
	while(cin>>s)
	{
		if(s=="0") break;
		s+="$";
		data["$"]=1;
		data["0"]=0;
		long long ans=solve(s);
		cout<<ans<<"\n";
		data.clear();
	}
}