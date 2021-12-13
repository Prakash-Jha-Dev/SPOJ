#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;

    while(t--)
    {
    	long long x,y,s,n,d,a;
    	cin>>x>>y>>s;
    	n=(s*2)/(x+y);
    	d=(y-x)/(n-5);
    	a=(x-2*d);
    	cout<<n<<"\n";
    	for(int i=1;i<=n;i++)
    	{
    		cout<<a<<" ";
    		a+=d;
    	}
    	cout<<"\n";
    }
}