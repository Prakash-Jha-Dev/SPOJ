#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

string src = "ALLIZZWELL";

vector< int > r_x {-1,-1,-1,0,0,1,1,1};
vector< int > r_y {-1,0,1,-1,1,-1,0,1};

bool solve(int x,int y, auto& v, int idx, auto s)
{
	s.insert({x,y});
	if(idx==10) return true;

	bool sol = false;
	for(int i=0;i<8;i++)
	{
		if(s.find({x+r_x[i], y+r_y[i]}) != s.end()) continue;
		if(v[x+r_x[i]][y+r_y[i]]==src[idx]) sol|=solve(x+r_x[i],y+r_y[i],v,idx+1,s);
	}
	return sol;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m;
		cin>>n>>m;

		vector< vector<char> >grid(n+2,vector<char>(m+2,'.'));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>grid[i][j];
			}
		}

		bool ans=false;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				set<pair<int,int>>s;
				if(grid[i][j]=='A') ans=solve(i,j,grid,1,s);
				if(ans)
				{
					i=n;j=m;
				}
			}
		}
		if(ans) cout<<"YES\n";
		else cout<<"NO\n";
	}
}