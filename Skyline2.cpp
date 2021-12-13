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
    int arr[1002][1001]={0};
    FOR(i,1,1001) arr[i][1]=1;

    FOR(i,2,1001)
    {
    	FOR(j,2,i-1)
    	{
    		arr[i][j]=(arr[i][j-1]+arr[i-1][j])%1000000;
    	}
    	arr[i][i]=arr[i][i-1];
    }
    int n;
    cin>>n;
    
    while(n!=0)
    {
    	cout<<arr[n+1][n]<<"\n";
    	cin>>n;
    }
    return 0;
}
