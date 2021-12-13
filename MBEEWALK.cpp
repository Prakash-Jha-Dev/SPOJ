#include <bits/stdc++.h>
using namespace std;

int ans=0;

void solve(int x, int y, int d)
{
	if(d==0)
	{
		if(x==y && x==0)
			ans++;
	}
	else
	{
		solve(x-1,y-1,d-1);
		solve(x+1,y+1,d-1);
		solve(x,y-1,d-1);
		solve(x,y+1,d-1);
		solve(x-1,y,d-1);
		solve(x+1,y,d-1);
	}
}

int main(void) 
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    vector<long long>sol{1,0, 6, 12, 90, 360, 2040, 10080, 54810, 290640, 1588356, 8676360, 47977776, 266378112, 1488801600, 8355739392, 47104393050, 266482019232, 1512589408044, 8610448069080};
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	cout<<sol[n]<<"\n";
    }
}