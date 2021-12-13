#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<long long int >arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    sort(arr.begin(), arr.end());
    long long ans = 0;
    if(arr.size() < 3)
    {
        cout<<arr.back();
        return 0;
    }

    long long temp = (arr[0] + arr[1]*2);
    for(int i=2; i+1<n; i+=2)
    {
        ans += min(arr[i]+arr[i+1]+arr[0]*2, temp+arr[i+1]);
    }
    if(n & 1)
    {
        ans += arr[n-1] + arr[0] + arr[1];
    }
    else
    {
        ans += arr[1];
    }
    cout<<ans;
}