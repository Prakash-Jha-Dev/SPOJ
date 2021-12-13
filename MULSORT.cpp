#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FOR(i,s,n) for(auto i = s; i != n; i++)
#define FORR(i,s,n) for(auto i = n; i != s; i--)
#define MOD 1000000007
#include <bits/stdc++.h>
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
struct Data
{
    double v;
    int r, c;
};

Data arr[2000005], arr2[2000005];


void merge(int st1, int ed1, int st2, int ed2)
{
    int j = 0, st = st1;
    while(st1 < ed1 && st2 < ed2)
    {
        if(arr[st1].v >= arr[st2].v)
        {
            arr2[j++] = arr[st1++];
        }
        else if(arr[st1].v < arr[st2].v)
        {
            arr2[j++] = arr[st2++];
        }
    }
    while(st1 < ed1) arr2[j++] = arr[st1++];
    while(st2 < ed2) arr2[j++] = arr[st2++];
    for(int k=0; k<j; k++) arr[st+k] = arr2[k];
} 


int main()
{
    int test;
    cin>>test;

    for(int kase=1;kase<=test;kase++)
    {
        int n,m;
        cin>>n>>m;
        int nm = n*m, idx;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                idx = i*m + j;
                cin>>arr[idx].v;
                arr[idx].r = i+1;
                arr[idx].c = j+1;
            }
        }

        int tn = m;
        while(m < nm)
        {
            int j;
            for(j=0; j+m<nm; j+=2*m)
                merge(j,j+m,j+m,j+2*m);
            if(j < nm && j+m >= nm)
                merge(j-2*m,j,j,nm);
            m *= 2;
        }
        for(int i=0; i<nm; i++) cout<<arr[i].r<<","<<arr[i].c<<" "; 
        cout<<"\n";
    }
}