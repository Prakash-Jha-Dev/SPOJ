#include <bits/stdc++.h>
using namespace std;

vector<int>pq;
vector<bool>hashed(1000,0);
vector<int>divisors(1000001,1);
void pre()
{
	for(int i=2;i<1000001;i++)
	{
		if(divisors[i]==1) pq.push_back(i);
		for(int j=i;j<1000001;j+=i)
		{
			divisors[j]++;
		}
	}
	for(int i=0;i<30;i++)
	{
		for(int j=i+1;pq[i]*pq[j]<1000;j++) hashed[pq[i]*pq[j]]=1;
	}
	int cnt=0;
	for(int i=1;i<1000001;i++)
	{
		if(hashed[divisors[i]])
		{
			cnt++;
			if(cnt%9==0) cout<<i<<"\n";
		}
		
	}
}
int main()
{
	pre();
}

