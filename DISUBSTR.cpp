#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
	int idx,firstRank,secondRank;
}data;

bool compare(data& p1, data& p2)
{
	if(p1.firstRank==p2.firstRank) return p1.secondRank<p2.secondRank;
	return p1.firstRank<p2.firstRank;
}

vector< vector<int> >tab( 17, vector<int>(50005) );
vector< data >arr(50005);
vector< int >lcp(50005),ran(50005);
void solve(string& s)
{

	for(int i=0; i<s.length(); i++)
		tab[0][i]=s[i];


	for(int cnt=1,step=1; cnt<s.length(); cnt<<=1, ++step)
	{
		for(int i=0; i<s.length(); i++)
		{
			arr[i].firstRank = tab[step-1][i];
			arr[i].secondRank = (i+cnt)<s.length()? tab[step-1][i+cnt]: -1;
			arr[i].idx=i;
		}

		sort(arr.begin(),arr.begin()+s.length(),compare);
		tab[step][arr[0].idx] = 0;
		for(int i=1,crank=0; i<s.length(); ++i)
		{
			if(arr[i-1].firstRank != arr[i].firstRank || arr[i-1].secondRank != arr[i].secondRank) crank++;
			tab[step][arr[i].idx] = crank;
		}
	}

	for(int i=0;i<s.size();i++) ran[arr[i].idx]=i;

	long long ans=0;
	for(int i=0,k=0; i<s.size(); i++, k?k--:0)
	{
		if(ran[i]==s.size()-1) 
		{
			k=0;
			continue;
		}
		int j=arr[ran[i]+1].idx;
		while(i+k<s.size() && j+k<s.size() && s[i+k]==s[j+k]) k++;
		lcp[ran[i]]=k;
		ans+=k;
	}

	cout<<((s.length()*(s.length()+1))/2 - ans)<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>s;
		solve(s);
	}
	return 0;
}