#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector< vector<int> >data{
        {9},
        {1},
        {2,4,8,7,5,1},
        {3,9},
        {4,7,1},
        {5,7,8,4,2,1},
        {6,9},
        {7,4,1},
        {8,1}
    };

    string a,b;
    cin>>a>>b;

    int v = 0;
    for(char c: a){
        v += (c-'0');
    }
    v %= 9;

    int p=0;
    for(char c: b){
        p = (p*10 + c-'0')%data[v].size();
    }

    if(data[v].back() == 9) {
        if(b.size() == 1) {
            if((b[0]-'0')<data[v].size()) {
                if((b[0]-'0'-1)>=0)
                cout<<data[v][b[0]-'0'-1];
                else cout<<data[v].back();
            }
            else {
                cout<<9;
            }
        }
        else {
            cout<<9;
        }
    }
    else {
        if(p-1 >= 0)
        cout<<data[v][p-1];
        else cout<<data[v].back();
    }
}