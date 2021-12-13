#include <bits/stdc++.h>
using namespace std;

__int128 fn(__int128 x, __int128 y,__int128 n)
{
	return (2*x*n + n*(n-5)*(y-x)/(n-6));
}
 
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;

    while(t--)
    {
    	long long x,y,s,n,d,a;
    	cin>>x>>y>>s;
    	s*=2;
    	long long ln=7,rn=100000;
    	while(ln<rn)
    	{
    		long long mid=(ln+rn+1)>>1;
    		long long temp=fn(x,y,mid);
    		if(temp<=s) 
    			ln=mid;
    		else
    			rn=mid-1;
    	}
    	n=ln;

    	d=(y-x)/(n-6);
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