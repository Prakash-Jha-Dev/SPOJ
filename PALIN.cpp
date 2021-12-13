#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;

		bool carry=true;
		for(int i=s.length()-1;i>=0 && carry;i--)
		{
			if(s[i]<'9') 
			{
				s[i]++;
				carry=false;
			}
			else
			{
				s[i]='0';
				carry=true;
			}
		}
		if(carry) s.insert(s.begin(),'1');

		string temp=s;

		if(s.length()%2==1)
		{
			int m=s.length()/2;
			for(int i=1; i<=m; i++)
			{
				if(s[m-i] < s[m+i])
				{
					for(int j=m-i; j<=m ; j++) s[j]=temp[j];
					if(s[m]<'9')
					{
						s[m]++;
						for(i=1;i<=m;i++)
						{
							s[m+i]=s[m-i];
						}
					}
					else
					{
						s[m]='0';
						bool carry=true;
						for(i=1;i<=m && carry;i++)
						{
							if(s[m-i]<'9')
							{
								s[m-i]++;
								carry=false;
							}
							else
							{
								s[m-i]='0';
								carry=true;
							}
						}
						for(i=1;i<=m;i++)
						{
							s[m+i]=s[m-i];
						}
					}
					break;
				}
				else if(s[m-i] > s[m+i])
				{
					for(;i<=m;i++) s[m+i]=s[m-i];
					break;
				}
			}
		}
		else
		{
			int m=s.length()/2;
			for(int i=1; i<=m; i++)
			{
				if(s[m-i] < s[m+i-1])
				{
					for(int j=m-i; j<m ; j++) s[j]=temp[j];
					if(s[m-1]<'9')
					{
						s[m-1]++;
						for(i=1;i<=m;i++)
						{
							s[m+i-1]=s[m-i];
						}
					}
					else
					{
						s[m-1]='0';
						bool carry=true;
						for(i=2;i<=m && carry;i++)
						{
							if(s[m-i]<'9')
							{
								s[m-i]++;
								carry=false;
							}
							else
							{
								s[m-i]='0';
								carry=true;
							}
						}
						for(i=1;i<=m;i++)
						{
							s[m+i-1]=s[m-i];
						}
					}
					break;
				}
				else if(s[m-i] > s[m+i-1])
				{
					for(;i<=m;i++) s[m+i-1]=s[m-i];
					break;
				}
			}
		}
		cout<<s<<"\n";
	}
}