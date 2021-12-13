#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	// ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;

    while(t--)
    {
    	int n,m,x;
    	cin>>n>>m;

    	char grid[n][m+1];

    	vector< vector<int> >dist(n, vector<int>(m,1000));

    	for(int i=0;i<n;i++)
    	{
    		scanf("%s",&grid[i][0]);
    		for(int j=0;j<m;j++)
    		{
    			if(grid[i][j]=='1')
    			{
    				for(int k=0;k<n;k++)
    				{
    					for(int l=0;l<m;l++)
    					{
    						dist[k][l]=min(dist[k][l], abs(k-i)+abs(l-j));
    					}
    				}
    			}
    		}
    	}
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			cout<<dist[i][j]<<" ";
    		}
    		cout<<"\n";
    	}
    }
}