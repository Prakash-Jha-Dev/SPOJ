#include <bits/stdc++.h>
using namespace std;
#define lld long long
#define SIZE 1000001

vector<bool>isprime(SIZE,1);
vector<int>n_prime(SIZE,0);
void pre()
{
	isprime[0]=0;isprime[1]=1;
	for(lld i=2;i<SIZE;i++)
	{
		if(isprime[i])
		{
			for(lld j=i*i;j<SIZE;j+=i) isprime[j]=0;
		}
	}
	for(int i=1;i<SIZE;i++) 
	{
		n_prime[i]=n_prime[i-1]+isprime[i];
	}
}

int ans,N;
vector<int>v;

void solve(int i, lld pro, bool sign)
{
	pro*=v[i];
	if(pro>N) return;
	if(sign) ans-=(N/pro);
	else ans+=(N/pro);

	sign^=1;
	for(int j=i+1;j<v.size();j++)
	solve(j,pro,sign);
}

int main()
{
	pre();
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int test;
	cin>>test;

	for(int kase=1;kase<=test;kase++)
	{
		int n,temp,ex=0;
		cin>>N>>n;

		set<lld>s;
		for(int i=0;i<n;i++) cin>>temp,s.insert(temp);
		n = s.size();
		v.clear();
		for(auto y:s) v.push_back(y),ex+=(y<=N);

		ans = N;
		for(int i=0;i<n;i++)
		solve(i,1,1);
		cout<<"Case "<<kase<<": "<<ans-n_prime[N]+ex<<"\n";
	}
}