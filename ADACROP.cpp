#include <bits/stdc++.h>
#include <ctime>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp>  
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q,x,y;
    cin>>n>>q;

    map<int, ordered_set >data;
    vector< int >arr(n);
    for(int i=0 ;i<n; i++) 
    {
        cin>>arr[i];
        data[arr[i]].insert(i);
    }

    set<int>::iterator it;
    while(q--)
    {
        cin>>x>>y;
        cout<<data[y].order_of_key(x)<<"\n";
        data[arr[x]].erase(x);
        arr[x] = y;
        data[arr[x]].insert(x);
    }
}