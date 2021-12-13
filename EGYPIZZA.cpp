#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n;
	string s;
	cin>>n;

	vector<int>arr(3,0);
	for(int i=0;i<n;i++)
	{
		cin>>s;

		if(s[0]=='1' && s[2]=='4') arr[0]++;
		else if(s[0]=='3') arr[2]++;
		else arr[1]++;
	}
	arr[0]=max(0,arr[0]-arr[2]);
	if((arr[1]&1) &&(arr[0]%4 >0 && arr[0]%4 <3))
	{
		arr[1]--;
	}

	int ans = 1;
	ans+=ceil(arr[0]/4.0);
	ans+=ceil(arr[1]/2.0);
	ans+=arr[2];
	cout<<ans;
}