#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q,x;
    string s;
    cin>>q;

    stack< pair<int,int> >st;
    st.push({-1,1000000000});

    while(q--)
    {
        cin>>s;
        if(s[1] == 'U')
        {
            cin>>x;
            st.push({x,min(x,st.top().second)});
        }
        else if(s[1] == 'O')
        {
            if(st.top().first != -1)
                st.pop();
            else cout<<"EMPTY\n";
        }
        else
        {
            if(st.top().first != -1) cout<<st.top().second<<"\n";
            else cout<<"EMPTY\n";
        }
    }
}