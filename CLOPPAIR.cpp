#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
	double y,x;
	int idx;
}point;

bool compare(point& p1, point& p2)
{
	return p1.x<p2.x;
}

inline bool operator<(const point&p1, const point&p2)
{
	return p1.y<p2.y;
}


void closest_point(vector<point> Points)
{
	sort(Points.begin(),Points.end(),compare);

	double best=999999999999.9;
	int a,b;
	set< point >box;
	int left=0;

	point temp=Points[0];
	box.insert(temp);

	for(int i=1;i<Points.size();i++)
	{
		while(left<i && Points[i].x-Points[left].x>best)
		{
			box.erase(Points[left++]);
		}

		auto it=box.lower_bound({Points[i].y-best, Points[i].x-best});

		while(it!=box.end() && Points[i].y+best>(it->y))
		{
			double dist=sqrt(pow(Points[i].y- it->y,2)+pow(Points[i].x - it->x,2));
			if(dist<best)
			{
				best=dist;
				a=it->idx;
				b=Points[i].idx;
			}
			it++;
		}
		box.insert(Points[i]);
	}
	if(a>b) swap(a,b);
	cout<<a<<" "<<b<<" ";
	cout<<fixed<<setprecision(6)<<best;
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector< point >Points(n);
	for(int i=0;i<n;i++) cin>>Points[i].x>>Points[i].y,Points[i].idx=i;

	closest_point(Points);
}