#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(void) 
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long x=0,y;
    int n;
    cin>>n;
    while(n--)
    {
    	cin>>y;
    	x^=y;
    }
    cout<<x;
}