#include <bits/stdc++.h>
using namespace std;

const long double PI = 3.14159265358979323846264338327950288419716939937510582097;
#define lld long long
vector< pair<long double, long double> >pts;;
vector< pair<long double,long double> >temp(103);
pair<long double,long double>check, chkx,chky;
long double calc(long double ang)
{
	chkx = {pts[0].first * cos(ang) + pts[0].second * sin(ang),pts[0].first * cos(ang) + pts[0].second * sin(ang)};
	chky = {-pts[0].first * sin(ang) + pts[0].second * cos(ang),-pts[0].first * sin(ang) + pts[0].second * cos(ang)};

	for(int i=0;i<pts.size();i++) 
	{
		temp[i].first = pts[i].first * cos(ang) + pts[i].second * sin(ang);
		temp[i].second = -pts[i].first * sin(ang) + pts[i].second * cos(ang);

		chkx.first = min(chkx.first, temp[i].first);
		chkx.second = max(chkx.second, temp[i].first);
		chky.first = min(chky.first, temp[i].second);
		chky.second = max(chky.second, temp[i].second);
	}
	check = {chkx.second - chkx.first, chky.second - chky.first};
	return check.first + check.second;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;

	pts.resize(n);

	for(int i=0;i<n;i++)
	{
		cin>>pts[i].first>>pts[i].second;
	}

	int cnt = 500;
	long double ma,mi,mid1,mid2,mid0,a1,a2,a0,l=0.0,r=PI;
	while(l<r && cnt--)
	{
		mid1 = l+(r-l)/3;
		mid2 = r-(r-l)/3;

		if(calc(mid1) > calc(mid2)) r = mid2;
		else l = mid1;
	}
	ma = calc(l);

	l=0.0,r=PI;
	while(l<r && cnt++<500)
	{
		mid1 = l+(r-l)/3;
		mid2 = r-(r-l)/3;

		if(calc(mid1) < calc(mid2)) r = mid2;
		else l = mid1;
	}
	mi = calc(l);

	cout<<fixed<<setprecision(10)<<mi<<" "<<ma<<"\n";
}