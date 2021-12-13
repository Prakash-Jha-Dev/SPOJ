// #include <bits/stdc++.h>
// using namespace std;

// vector< vector<int> >adj, cost, indexx;
// vector< vector<int> >par(15, vector<int>(10005));
// vector< int >depth,subsize,chainHead,chainInd,posInBase,baseArray,otherSide,segmentTree;
// int chainNo, ptr, lev;

// void build(int idx, int l, int r)
// {
// 	if(l==r-1)
// 	{
// 		segmentTree[idx]=baseArray[l];
// 		return;
// 	}
// 	int mid=(l+r)>>1;
// 	build(idx<<1,l,mid);
// 	build(idx<<1|1,mid,r);
// 	segmentTree[idx]=max(segmentTree[idx<<1],segmentTree[idx<<1|1]);
// }

// void update(int idx, int l, int r, int pos, int val)
// {
// 	if(r-1<pos || l>pos) return ;
// 	if(l==r-1 && l==pos)
// 	{
// 		segmentTree[idx]=val;
// 		return;
// 	}
// 	int mid=(l+r)>>1;
// 	update(idx<<1, l, mid, pos, val);
// 	update(idx<<1|1, mid, r, pos, val);
// 	segmentTree[idx]=max(segmentTree[idx<<1], segmentTree[idx<<1|1]);
// }

// int get(int idx, int l, int r, int beg, int end)
// {
// 	if(r<=beg || l>=end) return -1;
// 	if(beg<=l && r<=end)
// 	{
// 		return segmentTree[idx];
// 	}
// 	int mid=(l+r)>>1;
// 	int z=max(get(idx<<1,l,mid,beg,end), get(idx<<1|1,mid,r,beg,end));
// 	return z;
// }

// int lca(int u, int v)
// {
// 	if(depth[u] > depth[v]) swap(u,v);
// 	if(depth[u] < depth[v])
// 	{
// 		int diff=depth[v]-depth[u];
// 		for(int i=lev-1; i>=0; i--)
// 		{
// 			if(diff&(1<<i))
// 				v=par[i+1][v];
// 		}
// 	}
// 	if(u==v) return v;
// 	for(int i=lev;i>0;i--)
// 	{
// 		if(par[i][u]!=par[i][v])
// 		{
// 			u=par[i][u];
// 			v=par[i][v];
// 		}
// 	}
// 	return par[1][v];
// }

// void preLCA(int n=ptr)
// {
// 	for(int i=2; i<lev; i++)
// 	{
// 		for(int j=0;j<n;j++)
// 		{
// 			if(par[i-1][j]!=-1)
// 			par[i][j] = par[i-1][ par[i-1][j] ];
// 		}
// 	}
// }

// void HLD(int curr, int costTo, int prev)
// {
// 	if(chainHead[chainNo]==-1)
// 	{
// 		chainHead[chainNo]=curr;
// 	}
// 	chainInd[curr]=chainNo;
// 	posInBase[curr]=ptr;
// 	baseArray[ptr]=costTo;
// 	ptr++;
// 	// cout<<curr<<" "<<prev<<" "<<ptr<<" "<<chainNo<<"\n";

// 	int specialChild=-1,costToSpecialChild=-1;
// 	for(int i=0;i<adj[curr].size();i++)
// 	{
// 		if(adj[curr][i] != prev)
// 		if(specialChild ==-1 || subsize[specialChild] < subsize[ adj[curr][i] ])
// 		{
// 			specialChild = adj[curr][i];
// 			costToSpecialChild = cost[curr][i];
// 		}
// 	}
// 	if(specialChild != -1)
// 	{
// 		HLD(specialChild, costToSpecialChild, curr);
// 	}

// 	for(int i=0; i<adj[curr].size(); i++)
// 	{
// 		if(adj[curr][i] != specialChild && adj[curr][i]!= prev)
// 		{
// 			chainNo++;
// 			HLD(adj[curr][i], cost[curr][i], curr);
// 		}
// 	}
// }

// int query_till(int u, int v)
// {
// 	if(u==v) return 0;

// 	int ans=-1,x,y=chainInd[v];
// 	while(1)
// 	{
// 		x=chainInd[u];
// 		if(x==y)
// 		{
// 			if(u==v) break;
// 			ans=max(ans, get(1,0,ptr,posInBase[v]+1, posInBase[u]+1));
// 			break;
// 		}
// 		ans=max(ans, get(1,0,ptr,posInBase[ chainHead[x] ],posInBase[u]+1));
// 		u= chainHead[x];
// 		u= par[1][u];
// 	}
// 	return ans;
// }

// int query(int u, int v)
// {
// 	int l=lca(u,v);
// 	int ans1=query_till(u,l);
// 	int ans2=query_till(v,l);
// 	return max(ans1,ans2);
// }

// void change(int edge, int val)
// {
// 	int vertex=otherSide[edge];
// 	update(1,0,ptr,posInBase[vertex],val);
// }

// void dfs(int to, int from, int d)
// {
// 	depth[to]=d;
// 	par[1][to]=from;
// 	subsize[to]=1;
// 	for(int i=0;i<adj[to].size();i++)
// 	{
// 		if(adj[to][i]!=from)
// 		{
// 			otherSide[indexx[to][i]] = adj[to][i];
// 			dfs(adj[to][i],to,d+1);
// 			subsize[to]+=subsize[ adj[to][i] ];
// 		}
// 	}
// }

// void solve()
// {
// 	chainNo=0;ptr=0;lev=14;
// 	int n;
// 	cin>>n;
// 	adj.clear();adj.resize(n+5);
// 	cost.clear();cost.resize(n+5);
// 	indexx.clear();indexx.resize(n+5);
// 	chainHead.resize(n+5);
// 	chainInd.resize(n+5);
// 	depth.resize(n+5);
// 	subsize.resize(n+5);
// 	otherSide.resize(n+5);
// 	baseArray.resize(10005);
// 	posInBase.resize(n+5);
// 	segmentTree.resize(4*n+5);
// 	for(int i=0;i<n;i++) chainHead[i]=-1;
// 	for(int i=0;i<=14;i++) for(int j=0;j<n;j++) par[i][j]=-1;


// 	int x,y,c;
// 	for(int i=1;i<n;i++)
// 	{
// 		cin>>x>>y>>c;
// 		x--;y--;
// 		adj[x].push_back(y);
// 		cost[x].push_back(c);
// 		indexx[x].push_back(i-1);
// 		adj[y].push_back(x);
// 		cost[y].push_back(c);
// 		indexx[y].push_back(i-1);
// 	}

// 	dfs(0,-1,0);
// 	HLD(0,-1,-1);
// 	build(1,0,ptr);
// 	preLCA();

// 	string s;

// 	while(1)
// 	{
// 		cin>>s;
// 		if(s[0]=='D') break;
// 		cin>>x>>y;
// 		if(s[0]=='Q')
// 			cout<<query(x-1,y-1)<<"\n";
// 		else
// 			change(x-1,y);
// 	}
// }

// int main()
// {
// 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 		solve();
// 	}
// }


#include <bits/stdc++.h>
using namespace std;

vector< vector<int> >adj, cost, indexx;
vector< vector<int> >par(15, vector<int>(10005));
vector< int >depth,subsize,chainHead,chainInd,posInBase,baseArray,otherSide,segmentTree;
int chainNo=1, ptr=1, lev=14;

void build(int n=ptr)
{
	for(int i=n;i<n+n;i++) segmentTree[i]=baseArray[i-n];
	for(int i=n-1;i>0;i--) segmentTree[i]=max(segmentTree[i<<1], segmentTree[i<<1|1]);

}

void update(int pos, int val, int n=ptr)
{
	for(segmentTree[pos+=n]=val; pos>1; pos>>=1)
		segmentTree[pos>>1]=max(segmentTree[pos], segmentTree[pos^1]);
}

int get(int l, int r, int n=ptr, int ans=0) // Max in range [l,r]
{
	for(l+=n,r=r+n+1; l<r; l>>=1,r>>=1)
	{
		if(l&1) ans=max(ans, segmentTree[l++]);
		if(r&1) ans=max(ans, segmentTree[--r]);
	}
	return ans;
}

int lca(int u, int v)
{
	if(depth[u] > depth[v]) swap(u,v);
	if(depth[u] < depth[v])
	{
		int diff=depth[v]-depth[u];
		for(int i=lev-1; i>=0; i--)
		{
			if(diff&(1<<i))
				v=par[i+1][v];
		}
	}
	if(u==v) return v;
	for(int i=lev;i>0;i--)
	{
		if(par[i][u]!=par[i][v])
		{
			u=par[i][u];
			v=par[i][v];
		}
	}
	return par[1][v];
}

void preLCA(int n=ptr-1)
{
	for(int i=2; i<=lev; i++)
	{
		for(int j=1;j<=n;j++)
		{
			par[i][j] = par[i-1][ par[i-1][j] ];
		}
	}
}

void HLD(int curr, int costTo, int prev)
{
	if(chainHead[chainNo]==0)
	{
		chainHead[chainNo]=curr;
	}
	chainInd[curr]=chainNo;
	posInBase[curr]=ptr;
	baseArray[ptr]=costTo;
	// cout<<"indexx : "<<curr<<"  PosInBase: "<<ptr<<"\n";
	ptr++;

	int specialChild=-1,costToSpecialChild=-1;
	for(int i=0;i<adj[curr].size();i++)
	{
		if(adj[curr][i] != prev)
		if(specialChild ==-1 || subsize[specialChild] < subsize[ adj[curr][i] ])
		{
			specialChild = adj[curr][i];
			costToSpecialChild = cost[curr][i];
		}
	}
	if(specialChild != -1)
	{
		HLD(specialChild, costToSpecialChild, curr);
	}

	for(int i=0; i<adj[curr].size(); i++)
	{
		if(adj[curr][i] != specialChild && adj[curr][i]!= prev)
		{
			chainNo++;
			HLD(adj[curr][i], cost[curr][i], curr);
		}
	}
}

int query_till(int u, int v)
{
	if(u==v) return 0;

	int ans=0,x,y=chainInd[v];
	while(1)
	{
		x=chainInd[u];
		if(x==y)
		{
			if(u==v) break;
			ans=max(ans, get(posInBase[v]+1, posInBase[u]));
			break;
		}
		ans=max(ans, get(posInBase[ chainHead[ chainInd[u] ] ],posInBase[u]));
		u= chainHead[ chainInd[u] ];
		u= par[1][u];
	}
	return ans;
}

int query(int u, int v)
{
	int l=lca(u,v);
	int ans1=query_till(u,l);
	int ans2=query_till(v,l);
	return max(ans1,ans2);
}

void change(int edge, int val)
{
	int vertex=otherSide[edge];
	update(posInBase[vertex],val);
}

void dfs(int to, int from, int d)
{
	depth[to]=d;
	par[1][to]=from;
	subsize[to]=1;
	for(int i=0;i<adj[to].size();i++)
	{
		if(adj[to][i]!=from)
		{
			// cout<<"otherSide of edge "<<indexx[to][i]<<" is "<<adj[to][i]<<"\n";
			otherSide[indexx[to][i]] = adj[to][i];
			dfs(adj[to][i],to,d+1);
			subsize[to]+=subsize[ adj[to][i] ];
		}
	}
}

void solve()
{
	chainNo=1;ptr=1;
	int n;
	cin>>n;

	adj.clear();adj.resize(n+1);
	cost.clear();cost.resize(n+1);
	indexx.clear();indexx.resize(n+1);
	depth.clear();depth.resize(n+1);
	subsize.clear();subsize.resize(n+1);
	otherSide.clear();otherSide.resize(n+1);
	chainHead.clear();chainHead.resize(n+1);
	chainInd.clear();chainInd.resize(n+1);
	posInBase.clear();posInBase.resize(n+1);
	baseArray.clear();baseArray.resize(n+1);
	segmentTree.clear();segmentTree.resize(2*n +7);
	for(int i=1;i<=14;i++) par[i].clear(),par[i].resize(n+1);

	int x,y,c;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y>>c;
		adj[x].push_back(y);
		cost[x].push_back(c);
		indexx[x].push_back(i);
		adj[y].push_back(x);
		cost[y].push_back(c);
		indexx[y].push_back(i);
	}

	dfs(1,-1,0);
	HLD(1,-1,0);
	build();
	preLCA();
	// cout<<"otherSide\n";
	// for(int i=1;i<ptr;i++) cout<<otherSide[i]<<" "; cout<<"\n";
	// cout<<"Ptr :: "<<ptr<<"\n";
	string s;
	while(1)
	{
		cin>>s;
		if(s[0]=='D') break;
		// cout<<"\nsegmentTree\n";
		// for(int i=1;i<ptr+ptr+2;i++) cout<<segmentTree[i]<<" "; cout<<"\n";
		cin>>x>>y;
		if(s[0]=='Q')
			cout<<query(x,y)<<"\n";
		else
			change(x,y);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}