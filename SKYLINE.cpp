/*
@author: forgotter
Problem link: http://www.spoj.com/problems/SKYLINE/
*/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define MIN(x,y) ((x)<(y)?x:y)
#define MAX(x,y) ((x)>(y)?x:y)
#define EXCHANGE(x,y) ((x)=(x)^(y)^((y)=(x)))
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
#define INF 0x7fffffffffffffff

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) arr[i]=i+1;
    VI stat(n+1,0);
    int ans=0;
	do
	{
		vector<int>m(3,100);
		for(auto x: arr)
		{
			FOR(j,0,2) if(m[j]>x) {m[j]=x; break;}
		}
		if(m[2]==100)
		{
			stat[arr[0]]++;
			ans++;
		}
	}
	while(next_permutation(ALL(arr)));
	FOR(i,1,n) cout<<stat[i]<<" "; cout<<"\n";
	cout<<ans;
    return 0;
}
