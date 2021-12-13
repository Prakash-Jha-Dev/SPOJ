#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k)
{
	vector< pair<int, int> >arr;
	arr.push_back({0,0});
	int x,y;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		if(y<=k && x>0)
			arr.push_back({x,y});
	}

	n=arr.size()-1;

	int** sol=new int*[k+1];
	sol[0]=new int[k+1];
	sol[1]=new int[k+1];
	memset(sol[0],0,sizeof(int)*(k+1));
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k-arr[i].second;j++)
		{
			if(sol[i-1][j]+arr[i].first > sol[i-1][j+arr[i].second])
			{
				sol[i][j+arr[i].second]=sol[i-1][j]+arr[i].first;
			}
			else
				sol[i][j+arr[i].second]=sol[i-1][j+arr[i].second];
		}
		for(int j=0; j<arr[i].second ; j++)
			sol[i][j]=sol[i-1][j];

		sol[i+1]=new int[k+1];
		delete(sol[i-1]);
	}
	cout<<*max_element(sol[n],sol[n]+k+1)<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>k>>n;

	solve(n,k);
}