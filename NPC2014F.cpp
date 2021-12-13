#include <bits/stdc++.h>
#include <fstream>
#define lld long long int
using namespace std;
#define MOD 1000000007

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n;
	cin>>n;

	string str;
	cin>>str;

	cin>>n;
	vector< pair<char,int> >req;
	vector<int>req_v(26,0);
	char y;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		req.push_back({y,x});
		req_v[y-'a']=x;
	}

	int len = str.length()+1;
	int rl = 0,b=0,f;

	vector<int>avl(26,0);
	for(int i=0;i<=str.length();i++)
	{
		f=1;
		for(auto z:req)
		{
			if(z.second > avl[z.first-'a'] )
			{
				f = 0;
				break;
			}
		}

		if(f)
		{
			len = min(len,i-b);
			while(f & b<i)
			{
				len = min(len,i-b);
				avl[str[b]-'a']--;
				if(req_v[str[b]-'a'] > avl[str[b]-'a']) f=0;
				b++;
			}
		}
		if(i==str.length()) break;

		avl[str[i]-'a']++;
	}

	if(len <= str.length()) cout<<len;
	else cout<<"Andy rapopo";
}