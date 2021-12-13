#include <bits/stdc++.h>
#define lld unsigned long long
using namespace std;
#define N 20000001

vector<int>lpf(N);
vector< pair<int,lld> >cache(N);
void pre()
{
	cache[1]={1,1};
	for(int i=1;i<N;i++) lpf[i]=i;
	for(int i=2;i<N;i+=2) lpf[i]=2;
	int sq= sqrt(N) + 1, add;
	for(int i=3;i<N;i+=2) 
	{
		if(lpf[i]==i)
		{
			if(i<sq)
			{
				add = (i<<1);
				for(int j=i*i; j<N; j+=add)
				{
					lpf[j]=i;
				}
			}
		}
	}
}

//Function for pollard-rho algorithm
inline lld step_function(lld a, lld c, lld mod)
{
	return ((a*a)+c)%mod;
}

//To efficiently compute base^power % mod, used by miller-rabin method
inline lld modexp(lld base, lld power, lld mod)
{
	lld res=1;
	while(power)
	{
		if(power&1) (res*=base)%=mod;
		power>>=1;
		(base*=base)%=mod;
	}
	return res;
}

//Miller-rabin primality check
int s,d;
lld temp;
bool flag;
inline bool miller_rabin(lld num, lld k)
{
	s=0;d=num-1;
	while(!(d&1)) d>>=1,s++; //coverting n-1 into form of s*2^d

	temp=modexp(k,d,num); //computing initial k^d % n . 
	if(temp==1 || temp==num-1) return 1;	//Euclid's lemma temp congruent to -1 or 1 (mod n)
	for(int i=0;i<s;i++)
	{
		// for a num to be prime it's square should be congruent to -1 (mod n) and not 1 (mod n)
		temp=(temp*temp)%num;
		if(temp == 1) return 0;
		if(temp == num-1) return 1;
	}
	return 0; //if above conditions do not meet, it is not a prime
}

//Base array against which primalality check will be done
vector<int>base_prime{2,7,61};
inline bool isprime(int num)
{
	for(int x:base_prime) if(x==num) return 1; //if num is in base prime list, it is a prime
	if(!(num&1)) return 0; //if num is even, it is not prime 

	bool flag=true;
	for(int i=0;i<base_prime.size() && flag; i++) flag&=miller_rabin(num, base_prime[i]); 
	return flag;
}

//Return a number which might be a prime-factor of input number
inline lld pollard_rho(lld num)
{
	if(num == 1) return 1; //If num = 1, 1 is the only factor
	if(num%2 == 0) return 2; //All even numbers have 2 as its factor
	if(isprime(num)) return num;

	lld y=rand()%num+1, x, gcd=1, c = rand()%num +1; //set two variable with a random value [1,n)
	short sq = 30;
	x=y;

	while(sq--)
	{
		x=step_function(x, c, num); //Tortoise step
		y=step_function( step_function(y, c ,num), c , num ); //Hare step
		gcd=__gcd((x>y?x-y:y-x), num); //To compute if a factor exists
		if(gcd!=1)
		{
			if(gcd==num)
			{
				y=rand()%num+1;
				x=y;
				gcd=1;
			}
			else return gcd;
		}  
	}
	return num;
}

pair<int,lld> factorize(lld num)
{
	if(num<N && cache[num].first!=0) return cache[num];

	lld y;

	if(num < N) y=lpf[num];
	else
	{
		y = pollard_rho(num);
		while(!isprime(y)) y=pollard_rho(y);
	}
	lld tnum = num;
	num/=y;
	lld cnt = 2;
	lld rm = y, rs = 1+ y;
	while(num % y == 0)
	{
		cnt++;
		rm*=y;
		rs+=rm;
		num/=y;
	}
	pair<int,lld>tfac = factorize(num);
	tfac.first*=cnt;
	tfac.second*=rs;
	if(tnum<N) cache[tnum] = tfac;

	return tfac;
}

int main()
{
	// clock_t timer= clock();
	pre();
	int n;
	cin>>n;
	// n = 9;
	vector <int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v.begin(),v.end());

	lld msum_n = 0, mfac_n =0, msum_i = 1ULL<<32, mfac_i = 1ULL<<32;
	pair<int,lld>req;

	do
	{
		lld num = 0;
		for(auto &z:v)
		{
			num*=10;
			num+=z;
		}

		req=factorize(num);

		// req = cache[num];
		if(req.first > mfac_n)
		{
			mfac_n = req.first;
			mfac_i = num;
		}

		if(req.second > msum_n)
		{
			msum_n = req.second;
			msum_i = num;
		}
	}
	while(next_permutation(v.begin(),v.end()));

	cout<<mfac_i<<" "<<msum_i;
	
	// cout<<"\n"<<float(clock()-timer)/CLOCKS_PER_SEC<<"\n";
}