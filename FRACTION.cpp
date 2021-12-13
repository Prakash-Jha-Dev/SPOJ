#include<bits/stdc++.h>
using namespace std;

typedef struct 
{
	int num,den;
}fraction;

vector< fraction >data;

void farey(int n)
{
	data.clear();
	int a,b,c,d,p,q,r,s,k;
	a=0;b=1;c=1;d=n;
	fraction f;
	while(c<=n)
	{
		k=(n+b)/d;
		p=k*d-b;
		q=k*c-a;
		r=d;
		s=c;

		f.num=a;f.den=b;
		data.push_back(f);

		d=p;c=q;b=r;a=s;
	}
	f.num=1;f.den=1;
	data.push_back(f);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		int n,m,x;
		cin>>n>>m;
		farey(n);
		while(m--)
		{
			cin>>x;
			cout<<data[x-1].num<<"/"<<data[x-1].den<<"\n";
		}
	}
}