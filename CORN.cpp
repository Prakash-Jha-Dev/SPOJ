
#include <bits/stdc++.h>
using namespace std;
#define lld long long

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int test;
	cin>>test;
	string s;
	double r,se,h,mul;
	bool dec;
	
	while(test--)
	{
		cin>>s;
		mul = 1;
		dec = false;
		int i;
		r=0.0;
		for(i=0;i<s.length();i++)
		{
			if(s[i]=='e') 
			{
				i++;
				break;
			}
			if(s[i]=='.') 
			{
				mul=1;
				dec=true;
				continue;
			}

			if(!dec)
			{
				r*=10;
				r+=(s[i]-'0');
			}
			else
			{
				mul/=10;
				r+=((s[i]-'0')*mul);
			}
		}

		mul = 1;
		dec = false;
		se=0.0;
		for(;i<s.length();i++)
		{
			if(s[i]=='e') {i++;break;}
			if(s[i]=='.') 
			{
				mul=1;
				dec=true;
				continue;
			}

			if(!dec)
			{
				se*=10;
				se+=(s[i]-'0');
			}
			else
			{
				mul/=10;
				se+=((s[i]-'0')*mul);
			}
		}

		mul = 1;
		dec = false;
		h=0.0;
		for(;i<s.length();i++)
		{
			if(s[i]=='.') 
			{
				mul=1;
				dec=true;
				continue;
			}

			if(!dec)
			{
				h*=10;
				h+=(s[i]-'0');
			}
			else
			{
				mul/=10;
				h+=((s[i]-'0')*mul);
			}
		}
		float l = sqrt(r*r + h*h);
		long long ans = ceil(3.1415*r*l*se);
		cout<<ans<<"\n";
	}
}