#include <bits/stdc++.h>
using namespace std;

typedef struct
{
	int l,r,idx;
} q;

int n,m,s;
int arr[100001];
q query[100001];
int ans[100001];

bool compare(q&v1, q&v2)
{
	int x1=v1.l>>10, x2=v2.l>>10;

	if(x1==x2)
	{
		return v1.r<v2.r;
	}
	return x1<x2;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)
	{
		if(n==0) break;
		int freq[200001]={0};
		int mf[100001]={0};
		int sol=0;
	    cin>>m;
	    for(int i=1;i<=n;i++)    {cin>>arr[i];arr[i]+=100000;};
		for(int i=0;i<m;i++)
		{
			cin>>query[i].l>>query[i].r;
			query[i].idx=i;
		}

		sort(query,query+m,compare);

		int left=1,right=0,val=0;
		for(int i=0;i<m;i++)
		{
			while(right<query[i].r)
			{
				right++;
				freq[arr[right]]++;
				mf[freq[arr[right]]]++;
				sol=max(sol,freq[arr[right]]);
			}
			while(right>query[i].r)
			{
				mf[freq[arr[right]]]--;
				if(mf[sol]) ;
				else
				{
					sol-=1;
				}
				freq[arr[right]]--;
				right--;
			}
			while(left<query[i].l)
			{
				mf[freq[arr[left]]]--;
				if(mf[sol]) ;
				else
				{
					sol-=1;
				}
				freq[arr[left]]--;
				left++;
			}
			while(left>query[i].l)
			{
				left--;
				freq[arr[left]]++;
				mf[freq[arr[left]]]++;
				sol=max(sol,freq[arr[left]]);
			}
			ans[query[i].idx]=sol;
		}
		for(int i=0;i<m;i++) cout<<ans[i]<<"\n";
	}
}