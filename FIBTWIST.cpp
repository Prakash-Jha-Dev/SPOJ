#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007;

long long fib(int n)
{

    if(n==0) return 0;
    if(n==1 || n==2) return 1%MOD;
    if(n==3) return 2%MOD;
    unsigned long long res[2][2]={{1,1},{1,0}};
    unsigned long long mat[2][2]={{1,1},{1,0}};
    n-=2;

    long long p,q,r,s;
    while(n)
    {
        if(n&1)
        {
            p=(res[0][0]*mat[0][0] + res[0][1]*mat[1][0])%MOD;
            q=(res[0][0]*mat[0][1] + res[0][1]*mat[1][1])%MOD;
            r=(res[1][0]*mat[0][0] + res[1][1]*mat[1][0])%MOD;
            s=(res[1][0]*mat[0][1] + res[1][1]*mat[1][1])%MOD;
            res[0][0]=p;res[0][1]=q;res[1][0]=r;res[1][1]=s;
        }
        n>>=1;
        p=(mat[0][0]*mat[0][0] + mat[0][1]*mat[1][0])%MOD;
        q=(mat[0][0]*mat[0][1] + mat[0][1]*mat[1][1])%MOD;
        r=(mat[1][0]*mat[0][0] + mat[1][1]*mat[1][0])%MOD;
        s=(mat[1][0]*mat[0][1] + mat[1][1]*mat[1][1])%MOD;
        mat[0][0]=p;mat[0][1]=q;mat[1][0]=r;mat[1][1]=s;
    }
    return res[0][0];
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	
	int n,m;
	while(t--)
	{
		cin>>n>>m;
		MOD = m;
		cout<<((2*fib(n+2))%m -(n+2)%m +m)%m<<"\n";
	}	
}