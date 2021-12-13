#include <bits/stdc++.h>
using namespace std;

string s;
vector< vector< int > >tree(26, vector<int>(400005, 0)), lazy(26, vector<int>(400005, 0));

void build(int i, int idx, int l, int r)
{
    if(l == r)
    {
        if(s[l]-'a' == i)
            tree[i][idx] = 1;
        return;
    }

    int mid = (l+r)>>1;
    build(i, idx<<1, l, mid);
    build(i, idx<<1|1, mid+1, r);
    tree[i][idx] = (tree[i][idx<<1] + tree[i][idx<<1|1]);
}

void lazier(int i, int idx, int beg, int end)
{
    if(beg != end)
    {
        if(lazy[i][idx] == -1)
        {
            tree[i][idx<<1] = tree[i][idx<<1|1] = 0;
        }
        else
        {
            int mid = (beg+end)>>1;
            tree[i][idx<<1] = mid - beg + 1;
            tree[i][idx<<1|1] = end - mid;
        }
        lazy[i][idx<<1] = lazy[i][idx<<1|1] = lazy[i][idx];
    }
    lazy[i][idx] = 0;
}

void update(int i, int idx, int beg, int end, int l, int r, int val)
{
    if(beg > r || end < l) return;

    if(lazy[i][idx])
    {
        lazier(i, idx, beg, end);
    }

    if(beg >= l && end <= r)
    {
        tree[i][idx] = val*(end-beg+1);
        lazy[i][idx] = (val == 0? -1: 1);
        return;
    }
    int mid = (beg + end)>>1;
    update(i, idx<<1, beg, mid, l, r, val);
    update(i, idx<<1|1, mid+1, end, l, r, val);
    tree[i][idx] = tree[i][idx<<1] + tree[i][idx<<1|1];
}

int get(int i, int idx, int beg, int end, int l, int r)
{
    if(beg > r || end < l) return 0;

    if(lazy[i][idx])
    {
        lazier(i, idx, beg, end);
    }

    if(beg >= l && end <= r)
    {
        return tree[i][idx];
    }

    int mid = (beg + end)>>1;
    return get(i, idx<<1, beg, mid, l, r) + get(i, idx<<1|1, mid+1, end, l, r);
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;

    for(int i=0; i<26; i++)
    build(i,1,0,s.length()-1);

    int q, type, l, r;
    char c;
    cin>>q;

    while(q--)
    {
        cin>>type;
        if(type == 0)
        {
            cin>>l>>r>>c;
            if(l > r) swap(l,r);
            l--;r--;
            for(int i=0; i<26; i++)
            {
                if(i != c-'a')
                update(i, 1, 0, s.length()-1, l, r, 0);
            }
            update(c-'a', 1, 0, s.length()-1, l, r, 1);
        }
        else
        {
            cin>>l>>c;
            if(tree[c-'a'][1] < l) cout<<"-1\n";
            else
            {
                int left = 0, right = s.length()-1, mid, temp;
                while(left < right)
                {
                    mid = (left + right)>>1;
                    temp = get(c-'a', 1, 0 , s.length()-1, 0, mid);
                    if(temp >= l) right = mid;
                    else left = mid+1;
                }
                cout<<left+1<<"\n";
            }
        }
    }
}