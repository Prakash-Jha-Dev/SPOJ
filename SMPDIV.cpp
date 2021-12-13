#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;

    while(t--)
    {
    	int n,x,y;
    	cin>>n>>x>>y;

    	for(int i=x;i<n;i+=x)
    	{
    		if(i%y!=0)
    			cout<<i<<" ";
    	}
    	cout<<"\n";
    }
}