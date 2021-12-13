#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
 
inline long long power(long long num, int x)
{
	while(x--) num*=10;
	return num;
}

inline int le(long long num)
{
	return int(log10(num)+1);
}
 
vector< set<long long> >fa(14);
vector< long long >ans(5000005);
void pre()
{
	for(int i=2;i<14;i++) fa[i].insert(0);
	fa[2].insert(11);fa[2].insert(22);fa[2].insert(33);fa[2].insert(44);fa[2].insert(55);fa[2].insert(66);fa[2].insert(77);fa[2].insert(88);fa[2].insert(99);
	fa[3].insert(111);fa[3].insert(222);fa[3].insert(333);fa[3].insert(444);fa[3].insert(555);fa[3].insert(666);fa[3].insert(777);fa[3].insert(888);fa[3].insert(999);
 
	for(auto& it:fa[2])
	{
		if(it == 0) continue;
		for(auto& bt:fa[2])
		{
			fa[4].insert(it*100 +bt);
		}
	}
 
	for(auto& it:fa[2])
	{
		for(auto& bt:fa[3])
		{
			fa[5].insert(bt*100 +it);
			fa[5].insert(it*1000 +bt);
		}
	}
 
	long long rs = 279;
	int sz = 6;
 
	while(sz<13)
	{
		int szb = sz-2;
		for(auto& it:fa[2])
		{
			for(auto& bt:fa[szb])
			{
				fa[sz].insert(bt*100 +it);
				fa[sz].insert(power(it,szb)+bt);
			}
		}
		szb = sz-3;
		for(auto& it:fa[3])
		{
			for(auto& bt:fa[szb])
			{
				fa[sz].insert(bt*1000 +it);
				fa[sz].insert(power(it,szb)+bt);
			}
		}
		rs+=fa[sz].size();
		sz++;
	}
	int req = 2704281;

	auto i2 = fa[2].begin();
	auto i3 = fa[3].begin();
	
	i2++;
	i3++;

	auto i10 = fa[10].begin();
	auto i11 = fa[11].begin();

	long long n1,n2;
	while(fa[13].size() < req)
	{
		n1 = (*i2)*100000000000 + *i11;
		n2 = (*i3)*10000000000 + *i10;

		if(n1 < n2)
		{
			fa[13].insert(n1);
			i11++;
			if(i11 == fa[11].end())
			{
				i11 = fa[11].begin();
				i2++;
			}
		}
		else
		{
			fa[13].insert(n2);
			i10++;
			if(i10 == fa[10].end())
			{
				i10 = fa[10].begin();
				i3++;
			}
		}
	}
	for(int i=2;i<14;i++) fa[i].erase(0);
	int idx=1;
	for(int i=2;i<14;i++)
	{
		for(auto& it : fa[i])
		{
			if(le(it) ==i)
			ans[idx++] = it;
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
	pre();
 
	int t;
	cin>>t;
 
	while(t--)
	{
		int x;
		cin>>x;
		cout<<ans[x]<<"\n";
	}
}