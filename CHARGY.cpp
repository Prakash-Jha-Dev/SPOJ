#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n;

    stack<int>s;
    while(n--)
    {
        cin>>x;
        if(s.size())
        {
            if(s.top() && s.top() == -1*x)
            {
                s.pop();
            }
            else s.push(x);
        }
        else s.push(x);
    }
    cout<<s.size();
}
