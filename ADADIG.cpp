#include <bits/stdc++.h>
#include <fstream>
#define lld long long int
using namespace std;
#define MOD 1000000007

vector< lld >fact(3e5+5);
void pre()
{
	fact[0]=1;
	for(int i=1;i<=300000;i++) fact[i]=(fact[i-1]*i)%MOD;
}

lld modexp(lld base, lld power, lld mod=1000000007)
{
	lld res=1;
	while(power)
	{
		if(power&1) res=(res*base)%mod;
		power>>=1;
		base=(base*base)%mod;
	}
	return res;
}

lld invmod(lld num, lld mod=1000000007)
{
	if(num == 1) return 1;
	return modexp(num,mod-2,mod);
}

set<string>done;
lld s,ans;

void solve(auto& dig)
{
	sort(dig.begin(),dig.end());
	string chk="";
	for(auto i:dig) chk+=to_string(i);
	if(done.find(chk) != done.end()) return;

	done.insert(chk);
	for(int i=0;i<dig.size();i++)
	{
		for(int j=i+1;j<dig.size();j++)
		{
			if(dig[i]*dig[j] <10)
			{
				vector<int>temp{dig[i]*dig[j]};
				int k=0;
				while(k<i) temp.push_back(dig[k++]);
				k=i+1;
				while(k<j) temp.push_back(dig[k++]);
				k=j+1;
				while(k<dig.size()) temp.push_back(dig[k++]);

				solve(temp);
			}
		}
	}
}

int main()
{
	pre();
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;

	while(t--)
	{
		lld n,temp;
		cin>>n;
		temp = n;

		vector<int>dig;
		dig.clear();
		while(n%2==0) dig.push_back(2),n/=2;
		while(n%3==0) dig.push_back(3),n/=3;
		while(n%5==0) dig.push_back(5),n/=5;
		while(n%7==0) dig.push_back(7),n/=7;

		if(n>1)
		{
			cout<<0<<"\n";
		}
		else
		{
			n = temp;
			ans=0; s=0;
			done.clear();

			solve(dig);

			int hash[10];
			for(auto&x :done)
			{
				s = 0;
				memset(hash,0,10*sizeof(int));
				for(auto y:x) 
				{
					hash[y-'0']++;
					s+=(y-'0');
				}

				s = n - s;
				temp = fact[s + x.size()];
				for(int i=2;i<10;i++)	(temp*=invmod(fact[hash[i]]))%=MOD;
				(temp*=invmod(fact[s]))%=MOD;

				(ans+=temp)%=MOD;
			}
			cout<<ans<<"\n";
		}
	}
}