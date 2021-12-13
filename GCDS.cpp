#include <bits/stdc++.h>
using namespace std;
#define FACT_SIZE 10000001

vector<int>prime{2};
vector<int>fact(FACT_SIZE), rev(FACT_SIZE);
void pre()
{
	int sq = sqrt(FACT_SIZE) + 1;
	for(int i=2;i<FACT_SIZE;i+=2) fact[i]=2;
	for(int i=3;i<FACT_SIZE;i+=2)
	{
		if(!fact[i])
		{
			prime.push_back(i);
			fact[i]=i;
			if(i <= sq)
			{
				for(int j=i*i;j<FACT_SIZE;j+=i) 
				{
					fact[j]=i;
				}
			}
		}
	}

	for(int i=0;i<prime.size();i++) rev[prime[i]]=i;
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	pre();

	int test;
	cin>>test;

	while(test--)
	{
		int n,x;
		cin>>n;

		vector<bool>chk(prime.size());
		for(int i=0;i<n;i++)
		{
			cin>>x;
			while(x>1)
			{
				chk[rev[fact[x]]]=1;
				x/=fact[x];
			}
		}

		for(int i=0;i<prime.size();i++) if(!chk[i]) {cout<<prime[i]<<"\n";break;}
	}
}