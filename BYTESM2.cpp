#include <bits/stdc++.h>
using namespace std;

int n,m;
void solve(int x, int y, auto& grid, auto& sol, auto& done)
{
	done[x][y]=true;
	if(x==n+1 || y==0 || y==m+1) return ;
	if(!done[x+1][y])
	{
		solve(x+1,y, grid, sol, done);
	}
	if(!done[x+1][y-1])
	{
		solve(x+1,y-1, grid, sol, done);
	}
	if(!done[x+1][y+1])
	{
		solve(x+1,y+1, grid, sol, done);
	}
	sol[x][y]=grid[x][y]+max({sol[x+1][y-1], sol[x+1][y], sol[x+1][y+1]});
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    	cin>>n>>m;
    	vector< vector<int> >grid(n+2, vector<int>(m+2,0));

    	vector< vector<int> >sol(n+2, vector<int>(m+2,0));
    	vector< vector<bool> >done(n+2, vector<bool>(m+2,0));

    	for(int i=1;i<=n;i++)
    		for(int j=1;j<=m;j++)
    			cin>>grid[i][j];

    	for(int i=1;i<=m;i++)
    		solve(1,i,grid, sol, done );

    	int ans=0;
    	for(int i=1;i<=m;i++) ans=max(ans,sol[1][i]);
    	cout<<ans<<"\n";
    }
}