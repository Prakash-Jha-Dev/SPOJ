#include <bits/stdc++.h>
using namespace std;
#define SIZE 1501

int dpa[SIZE][SIZE];
int dpw[SIZE][SIZE];
int dpf[SIZE][SIZE];

int ans=0;

int air(int , int);
int water(int, int);
int fire(int, int);

void solve()
{
	int h,a;
	cin>>h>>a;
	cout<<dpa[h][a]<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;

	memset(dpf,-1,sizeof dpf);
	memset(dpw,-1,sizeof dpw);
	memset(dpa,-1,sizeof dpa);

	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
			air(i,j);

	while(t--) solve();
}

int fire(int h, int a)
{
	// cout<<"fire "<<h<<" "<<a<<"\n";
	if(h<=0 || a<=0)	return 0;
	if(dpf[h][a]!=-1)	return dpf[h][a];
	if(h-20>0)
		dpf[h][a]=air(h-20,a+5)+1;
	else
		return 0;
	return dpf[h][a];
}

int water(int h, int a)
{
	// cout<<"water "<<h<<" "<<a<<"\n";
	if(h<=0 || a<=0)	return 0;
	if(dpw[h][a]!=-1)	return dpw[h][a];
	if(h-5>0 && a-10>0)
		dpw[h][a]=air(h-5,a-10)+1;
	else
		return 0;
	return dpw[h][a];
}

int air(int h, int a)
{
	// cout<<"air "<<h<<" "<<a<<"\n";
	if(h<=0 || a<=0) return 0;
	if(dpa[h][a]!=-1) return dpa[h][a];
	dpa[h][a]=max(fire(h+3,a+2),water(h+3,a+2))+1;
	return dpa[h][a];
}