#include <bits/stdc++.h>
using namespace std;

int val(char c)
{
	if(c=='+') return 3;
	if(c=='-') return 3;
	if(c=='*') return 2;
	if(c=='/') return 2;
	if(c=='^') return 1;
	if(c=='(' || c==')') return 4;
}

void solve()
{
	string s;
	cin>>s;
	stack<char>exp;
	stack<char>ans;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='a' && s[i]<='z')
		{
			ans.push(s[i]);
		}
		else
		{
			if(s[i]=='(')
			exp.push(s[i]);
			else if(s[i]==')')
			{
				while(exp.top()!='(')
				{
					ans.push(exp.top());
					exp.pop();
				}
				exp.pop();
			}
			else
			{
				while(!exp.empty() && val(s[i])>val(exp.top()))
				{
					ans.push(exp.top());
					exp.pop();
				}
				exp.push(s[i]);
			}
		}
	}
	while(!exp.empty())
	{
		ans.push(exp.top());
		exp.pop();
	}

	string sol;
	while(!ans.empty())
	{
		sol.push_back(ans.top());
		ans.pop();
	}
	reverse(sol.begin(),sol.end());
	cout<<sol<<"\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}