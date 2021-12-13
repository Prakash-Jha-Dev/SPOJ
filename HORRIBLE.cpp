#include <bits/stdc++.h>
using namespace std;

long long arr1[100005],arr2[100005];

void modify( long long *arr,int l, int n, long long val)
{
	l++;
	while(l<=n)
	{
		arr[l]+=val;
		l+=(l&-l);
	}
}

long long sum(int l,long long *arr)
{
	long long ans=0;
	l++;
	while(l)
	{
		ans+=arr[l];
		l-=(l&-l);
	}
	return ans;
}

void update(int l ,int r,int n, long long val)
{
	modify(arr1,l,n,val);
	modify(arr1,r+1,n,-val);

	modify(arr2,l,n,val*(l-1));
	modify(arr2,r+1,n,-val*r);
}

long long get(int l, int r)
{
	return ((sum(r,arr1)*r)-sum(r,arr2))-((sum(l-1,arr1)*(l-1))-sum(l-1,arr2));
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,c,p,q,a,val;
		cin>>n>>c;
		memset(arr1,0,100001*sizeof(long long));
		memset(arr2,0,100001*sizeof(long long));

		while(c--)
		{
			cin>>a;
			if(a==0)
			{
				cin>>p>>q>>val;
				update(p-1,q-1,n,val);
			}
			else
			{
				cin>>p>>q;
				cout<<get(p-1,q-1)<<"\n";
			}
		}
	}
}