/*
Code witten by :forgotter
Problem : AGGRCOW - Aggressive cows
*/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define MIN(x,y) ((x)<(y)?x:y)
#define MAX(x,y) ((x)>(y)?x:y)
#define MOD 1000000007

#define PII pair<int,int>
#define PIVLLD pair<int, vector<int64_t>
#define PIVI pair<int, vector<int> >
#define PIS pair<int, string>
#define VI vector<int>
#define VLLD vector<int64_t>
#define VS vector<string>
#define OUT(it,x) for(auto (it)=(x).begin();(it)!=(x).end();(it)++) cout<<*(it)<<" "; cout<<"\n"
#define POUT(it,Begin,End) for(auto (it)=(Begin);(it)!=(END);(it)++) cout<<*(it)<<" "; cout<<"\n"
#define FOR(i,b,e) for(int (i)=(b); (i)<=(e); (i)++)
#define RFOR(i,b,e) for(int (i)=(b); (i)>=(e); (i)--)
#define ALL(x) (x).begin(),(x).end()

#define DEBUG1(x) cout<<"\nDebugging "<< x<<"\n"
#define DEBUG2(x,y) cout<<"\nDebugging "<< x<<" "<<y<<"\n"
#define DEBUG3(x,y,z) cout<<"\nDebugging "<< x<<" "<<y<<" "<<z<<"\n"
#define DEBUG4(x,y,z,zz) cout<<"\nDebugging "<< x<<" "<<y<<" "<<z<<" "<<zz<<"\n"

#define lld int64_t
#define INF 0xfffffff

lld bs(VLLD &arr, int l,int r, lld val)
{
	while(l<r)
	{
		int m=(l+r)/2;
		if(arr[m]>=val) r=m;
		else l=m+1;
	}
	return arr[l];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,c;
		cin>>n>>c;
		VLLD arr(n);
		FOR(i,0,n-1) cin>>arr[i];
		sort(arr.begin(),arr.end());
		lld ans1=0,ans2=arr.back()-arr.front();
		while(ans1<ans2)
		{
			lld temp=(ans1+ans2+1)/2;
			bool f=true;
			lld b=arr.front();
			FOR(i,2,c)
			{
				lld next=bs(arr,0,arr.size()-1,b+temp);
				if(next>=b+temp)
					b=next;
				else
				{
					f=false;
					break;
				}
			}
			if(f)
			{
				ans1=temp;
			}
			else
			{
				ans2=temp-1;
			}
		}
		cout<<ans1<<"\n";
	}
}