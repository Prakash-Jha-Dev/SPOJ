#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test,n;
    cin>>test;
    while(test--)
    {
    	cin>>n;
    	vector< pair<int,int> >arr(n);
    	for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
    	sort(arr.begin(),arr.end());
    	int ans=0,currb=-1,curre=-1;
    	for(int i=0;i<n;i++)
    	{
    		if(arr[i].first>=curre)
    		{
    			currb=-1,curre=-1;
    		}

    		if(currb==-1)
    		{
    			ans++;
    			currb=arr[i].first;
    			curre=arr[i].second;
    		}
    		else
    		{
    			if(arr[i].second<curre)
    				curre=arr[i].second;
    		}
    	}
    	cout<<ans<<"\n";
	}
}