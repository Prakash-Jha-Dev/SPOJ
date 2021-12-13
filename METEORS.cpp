#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long long

vector< lld >tree(3e5+5),ql(3e5+5,0),qr(3e5+5,0),qa(3e5+5,0),req(3e5+5),low(3e5+5),high(3e5+5);
vector< vector<lld> >arr(3e5+5, vector<lld>()),todo(3e5+5, vector<lld>()) ;
int n,m;

void update(int pos, lld val)
{
	while(pos<=m)
	{
		tree[pos]+=val;
		pos+=(pos&(-pos));
	}
}

lld get(int pos)
{
	lld ans=0;
	while(pos>0)
	{
		ans+=tree[pos];
		pos-=(pos&(-pos));
	}
	return ans;
}

void apply(int i)
{
	if(ql[i]<=qr[i]) 
	{
		update(ql[i],qa[i]);
		update(qr[i]+1,-qa[i]);
	}
	else
	{
		update(1,qa[i]);
		update(qr[i]+1,-qa[i]);
		update(ql[i],qa[i]);
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int x;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
    	cin>>x;
    	arr[x].push_back(i);
    }

    for(int i=1;i<=n;i++)
    {
    	cin>>req[i];
    }

    int q,l,r;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>ql[i]>>qr[i]>>qa[i];
	}

	for(int i=1;i<=n;i++)
	{
		low[i]=1;
		high[i]=q+1;
	}

	bool changed=true;

	while(changed)
	{
		changed=false;
		for(int i=1;i<=m;i++) tree[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(low[i]!=high[i])
			todo[(low[i]+high[i])>>1].push_back(i);
		}

		for(int i=1;i<=q;i++)
		{
			apply(i);

			while(todo[i].size())
			{
				changed=true;
				int idx=todo[i].back();
				todo[i].pop_back();

				lld s=0;
				for(auto y:arr[idx]) s+=get(y);

				if(s>=req[idx]) high[idx]=i;
				else low[idx]=i+1;
			}			
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(low[i]<=q) cout<<low[i]<<"\n";
		else cout<<"NIE\n";
	}
    return 0;
}
