#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define lld long long

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;

	for(int test=1;test<=t;test++)
	{
		cout<<"Scenario #"<<test<<":\n";
		
		int n,e,x,y;
		cin>>n>>e;
		bool flag=true;
		set<int>adj[n+1];

		for(int i=0;i<e;i++)
		{
			cin>>x>>y;
			adj[x].insert(y);
			adj[y].insert(x);
		}

		vector<bool>vis(n+1,0);
		vector<int>col(n+1,0);

		set<int>tov;
		for(int i=1;i<=n;i++) tov.insert(i);

		while(!tov.empty())
		{
			int f=*tov.begin();
			tov.erase(f);

			queue<int>ord;
			ord.push(f);
			col[f]=1;
			vis[f]=1;
			while(!ord.empty())
			{
				int x=ord.front();
				ord.pop();
				for(auto y:adj[x])
				{
					if(!vis[y])
					{
						tov.erase(y);
						vis[y]=1;
						ord.push(y);
					}

					if(col[y])
					{
						if(col[y]==col[x])
							flag=false;
					}
					else
					{
						if(col[x]==1)	col[y]=2;
						else	col[y]=1;
					}
				}
			}
		}

		flag?cout<<"No suspicious bugs found!\n":cout<<"Suspicious bugs found!\n";
	}
}