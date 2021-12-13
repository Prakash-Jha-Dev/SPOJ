#include <bits/stdc++.h>
using namespace std;
#define lld long long

int fact[10000001];
int n[10000001];
void pre()
{
	// for(int i=1;i<10000001;i++) fact[i]=i;
	for(int i=2;i<10000001;i+=2) fact[i]=2,n[i]=(i>>1);
	for(int i=3;i<10000001;i+=2)
	{
		if(!fact[i])
		{
			fact[i]=i;
			if(i<3163)
			{
				int k=i<<1;
				for(int j=i*i;j<10000001;j+=k)
				{
					if(!fact[j])	fact[j]=i,n[j]=(j/i);
				}
			}
		}
	}
}


int main()
{
	// ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int x;
	int f[250];
	while(scanf("%d",&x)!=EOF)
	{
		f[0]=1;
		int j=0;
		while(x>1)
		{
			f[++j]=fact[x];
			x=n[x];
		}
		for(int i=0;i<j;i++) printf("%d x ",f[i]);
		printf("%d\n",f[j]);
	}
	return 0;
}