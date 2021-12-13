#include<bits/stdc++.h>
using namespace std;

typedef struct 
{
	long long prefix,suffix,middle,sum,best;
}data;

long long A[50005];
data arr[200005];

void cal(data& d, data& a, data& b)
{
	d.prefix= max(a.prefix, a.sum+b.prefix);
	d.suffix= max(b.suffix, a.suffix+b.sum);
	d.middle= a.suffix+b.prefix;
	d.sum= a.sum+b.sum;
	d.best= max({d.prefix, d.suffix, d.sum, d.middle, a.best, b.best});
}

void setter(data& d,long long val)
{
	d.prefix=d.suffix=d.middle=d.sum=d.best=val;
}

void build(int idx, int l, int r)
{
	if(l==r)
	{
		setter(arr[idx],A[l]);
		return;
	}
	int m=(l+r)>>1;
	build(idx<<1, l, m);
	build(idx<<1|1, m+1, r);
	cal(arr[idx], arr[idx<<1], arr[idx<<1|1]);
}

data get(int idx, int l, int r, int beg, int end)
{
	data temp,left,right;
	setter(temp,-1000000000);
	if(l>end || r<beg) return temp;

	if(beg<=l && r<=end)	return arr[idx];
	int mid=(l+r)>>1;
	left= get(idx<<1, l, mid, beg, end);
	right= get(idx<<1|1, mid+1, r, beg, end);
	cal(temp, left, right);
	return temp;
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>A[i];

	build(1,0,n-1);
	int q,l,r;
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		cout<<get(1,0,n-1,l-1,r-1).best<<"\n";
	}
}