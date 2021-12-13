#include <bits/stdc++.h>
using namespace std;
 
vector<long long>arr;
 
void solve(int i, int j, auto& sol, auto& done, int year)
{
	if(done[i][j]) return;
	done[i][j]=1;
 
	if(i==j)
	{
		sol[i][j]=arr[i]*year;
		return;
	}
	else 
	{
		if(!done[i+1][j]) solve(i+1,j,sol,done,year+1);
		if(!done[i][j-1]) solve(i,j-1,sol,done,year+1);
		sol[i][j]=max(arr[i]*year+sol[i+1][j], arr[j]*year+sol[i][j-1]);
		return;
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;
 
    arr.resize(n+1);
 
    for(int i=1;i<=n;i++) cin>>arr[i];
 
    vector< vector<long long> > sol(n+1, vector<long long>(n+1, 0));
    vector< vector<bool> >done(n+1, vector<bool>(n+1, 0));
 
 
    solve(1,n, sol, done, 1);
    cout<<sol[1][n];
}