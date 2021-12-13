#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int val;
bool comp(vector<int>&v1,  vector<int>&v2)
{
	int l1=v1[0]/val;
	int l2=v2[0]/val;
	if(l1!=l2) return (l1 < l2);
	return v1[1]<v2[1];
}

int arr[300001];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	int q;
	scanf("%d",&q);
	vector< vector<int> > query(q, vector<int>(3));
	vector<int>sol(q);

	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&query[i][0],&query[i][1]);
		query[i][2]=i;
	}
	val=sqrt(n);
	sort(query.begin(),query.end(),comp);

	int l=1,r=0,diff=0;
	vector<int>fr(1000001,0);
	for(const auto& x: query)
	{
		while(r>x[1])
		{
			fr[arr[r]]--;

			if(fr[arr[r]]==0) diff--;

			--r;
		}
		while(l<x[0])
		{
			fr[arr[l]]--;

			if(fr[arr[l]]==0) diff--;

			l++;
		}
		while(r<x[1])
		{
			++r;
			fr[arr[r]]++;

			if(fr[arr[r]]==1) diff++;
		}
		while(l>x[0])
		{
			l--;

			fr[arr[l]]++;

			if(fr[arr[l]]==1) diff++;
		}
		sol[x[2]]=diff;
	}
	for(int x:sol) printf("%d\n",x);
}