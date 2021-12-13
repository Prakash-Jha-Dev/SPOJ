#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long long

inline lld multiply(lld a, lld b, lld mod)
{
	lld res = 0;
	while(b)
	{
		if(b&1) res=(res+a)%mod;
		a = (a<<1)%mod;
		b>>=1;
	}
	return res;
}

inline lld fun(lld a, lld c, lld mod)
{
	return (multiply(a,a,mod)+c)%mod;
}

lld pollard_rho(lld num)
{
	if(num==1) return 1;
	if(num%2 == 0) return 2;

	lld y=rand()%num+1, x, gcd=1, sq=10000, c = rand()%num +1;
	x=y;

	while(gcd==1)
	{
		if(sq-- <1) return num;
		x=fun(x, c, num);
		y=fun( fun(y, c ,num), c , num );
		if(x==y) gcd=num;
		else	gcd=__gcd((x>y?x-y:y-x), num);
		if(gcd!=1)
		{
			if(gcd==num)
			{
				y=rand()%num+1;
				x=y;
				gcd=1;
			}
			else
				break;
		}  
	}
	return gcd;
}

inline lld modexp(lld base, lld power, lld mod)
{
	lld res=1;
	while(power)
	{
		if(power&1) res=multiply(res,base,mod);
		power>>=1;
		base=multiply(base,base,mod);
	}
	return res;
}

bool miller_rabin(lld num, lld k)
{
	lld s=0,d=num-1,temp;
	while(!(d&1)) d>>=1,s++;

	bool flag=true;
	temp=modexp(k,d,num);
	if(temp==1 || temp==num-1) return 1;
	for(int i=0;i<s;i++)
	{
		temp=multiply(temp,temp,num);
		if(temp==1) return 0;
		if(temp==num-1) return 1;
	}
	return 0;
}

vector<int>A{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
bool prime(lld num)
{
	// cout<<num<<" as a factor"<<"\n";
	for(auto x:A) if(x==num) return 1;
	if(!(num&1)) return 0;

	bool flag=true;
	for(int i=0;i<A.size() && flag; i++) flag&=miller_rabin(num, A[i]);
	return flag;
}

int main()
{
	srand(time(0));
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int test;
	cin>>test;
	while(test--)
	{
		lld x,y,inp;
		cin>>x;
		inp = x;
		lld ans=1,rs,rm,tans=1,trs,trm;

		while(x!=1)
		{
			y=pollard_rho(x);
			int count=1;
			while(!prime(y)) y=pollard_rho(y);
			x/=y;
			trm = y;
			trs = 1 + y;
			while(x%y==0)
			{
				x/=y;
				count++;
				trm *= y;
				trs += trm;
			}
			tans*=trs;
		}
		cout<<tans-inp<<"\n";
	}
}