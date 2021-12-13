#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int test=1;test<=t;test++)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)	cin>>arr[i];

		int* temp_arr=new int[n+1];
		int k=n+1;
		for(int i=0;i<n;i++) temp_arr[i]=arr[i];
		temp_arr[n]=0;
		sort(temp_arr,temp_arr+k);
		for(int i=0;i<n;i++)	arr[i]=lower_bound(temp_arr,temp_arr+k,arr[i])-temp_arr;
		delete(temp_arr);

		int fen[k],idx;
		memset(fen,0,sizeof fen);
		long long inv=0;
		for(int i=n-1;i>=0;i--)
		{
			idx=arr[i]-1;
			while(idx)
			{
				inv+=fen[idx];
				idx=(idx&(idx-1));
			}
			idx=arr[i];
			while(idx<k)
			{
				fen[idx]++;
				idx+=(idx&(-idx));
			}
		}
		cout<<inv<<"\n";
	}
}