#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;

    for(int test=1;test<=t;test++)
    {     
        int x,n,y;
        cin>>x>>n;
        long long ans=0; 
        vector<int>h(2001);
        for(int i=0; i<n; i++)
        {
        	cin>>y;
        	if(x-y >=0)
        	ans +=  h[x-y]; 
        	h[y]++; 
        }
        cout<<test<<". "<<ans<<"\n"; 
    }

	return 0;
}