#include <bits/stdc++.h>
using namespace std;

void manchar(string& str)
{
	string s="#";
	for(auto x:str) s=s+x+"#";

	vector<int>P(s.length(),0);
	int center=0,right=-1,radius,best=0,no=0;

	for(int i=0;i<s.length();i++)
	{
		if(i<=right)
			radius=min(P[2*center - i], right-i);
		else
			radius=0;

		while(i+radius<s.length() && i-radius>=0 && s[i+radius]==s[i-radius])
			radius++;

		P[i]=radius;
		best=max(best,P[i]);
		if(i+radius-1 >right)
		{
			center=i;
			right=i+radius-1;
		}
	}
	best-=1;
	for(int i=0;i<s.length();i++) 
	{
		P[i]-=1;
		if(P[i]==best) no++;
	}

	cout<<best<<" "<<no<<"\n";
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;

	for(int test=1;test<=t;test++)
	{
		string s;
		cin>>s;
		manchar(s);
	}
}