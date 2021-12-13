#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
	double y,x;
	int idx;
}point;

bool compare(point& p1, point& p2)
{
	return (p1.y<p2.y)||(p1.y==p2.y && p1.x<p2.x);
}

bool cross(point& o, point& a, point& b)
{
	return ((a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y))<=0;
}

void AndrewHull(auto& arr)
{
	sort(arr.begin(),arr.end(),compare);
	int n=arr.size();
	vector< point >hull(2*n);
	int k=0;

	for(int i=0;i<n;i++)
	{
		while(k>=2 && cross(hull[k-2],hull[k-1],arr[i])) k--;
		hull[k++]=arr[i];
	}

	int t=k+1;
	for(int i=n-2;i>=0;i--)
	{
		while(k>=t && cross(hull[k-2],hull[k-1],arr[i])) k--;
		hull[k++]=arr[i];
	}

	hull.resize(k-1);
	n=hull.size();
	double cur=0;
	for(int i=1;i<n;i++)
	{
		cur+=sqrt(pow(hull[i].x-hull[i-1].x,2)+pow(hull[i].y-hull[i-1].y,2));
	}
	cur+=sqrt(pow(hull.back().x-hull.front().x,2)+pow(hull.back().y-hull.front().y,2));

	cout<<fixed<<setprecision(2)<<cur<<"\n";
	for(auto x:hull) cout<<x.idx<<" "; cout<<"\n";
}

void solve()
{
	map< pair<double,double>, int >done;

	int n;
	cin>>n;
	vector<point>arr(n);
	double x,y;
	int j=0;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		arr[i].x=x;
		arr[i].y=y;
		j++;
		auto it=done.find({x,y});
		if(it!=done.end())
		{
			arr[i].idx=it->second;
			j--;
		}
		else
		{
			arr[i].idx=i+1;
			done[{x,y}]=i+1;
		}
	}

	if(j==1) cout<<"0.00\n1\n";
	else	AndrewHull(arr);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;

	while(t--)
	{
		solve();
		cout<<"\n";
	}
}