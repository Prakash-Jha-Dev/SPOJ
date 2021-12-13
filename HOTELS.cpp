#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    long long n,m,p=0,idx=0;
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>m;
    
    for(int i=0;i<n;i++)
    {
        if(i-m>idx)
        {
            int temp=arr[++idx];
            while(p<=i)
            {
                if(arr[p]>temp)
                {
                    temp=arr[p];
                    p++;
                }
            }
        }
    }
    cout<<ans;
}