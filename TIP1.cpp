#include <bits/stdc++.h>
using namespace std;
#define lld long long

vector<int>phi(10000001);
vector< int >perm(10000001);

bool is_perm(int n1, int n2)
{
	int rem;
	vector<int>cnt(10,0);
	while(n1)
	{
		cnt[n1%10]++;
		n1/=10;
	}
	while(n2)
	{
		cnt[n2%10]--;
		n2/=10;
	}
	for(int i=0;i<10;i++)
	{
		if(cnt[i]) return false;
	}
	return true;
}
void pre()
{
	for(int i=1;i<10000001;i++) phi[i]=i;
	for(int i=2;i<10000001;i++)
	{
		if(phi[i]==i)
		{
			for(int j=i;j<10000001;j+=i) phi[j]-=(phi[j]/i);
		}
	}
	perm[21]=21;
	pair<long long,long long>temp{21,12};
	for(int i=22;i<10000001;i++)
	{
		if(is_perm(i,phi[i])) 
		{
			if(i*temp.second <= phi[i]*temp.first)
			{
				temp={i,phi[i]};
			}
			perm[i]=temp.first;
		}
		else perm[i]=temp.first;
	}
}

int main()
{
	pre();
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int test,n;
	cin>>test;
	while(test--)
	{
		cin>>n;
		n--;
		if(n<21) cout<<"No solution.\n";
		else cout<<perm[n]<<"\n";
	}
}