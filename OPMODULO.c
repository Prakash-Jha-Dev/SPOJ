#include <stdio.h>

unsigned long long get(unsigned long long num)
{
	if(num ==0) return 0;

	unsigned long long ans=0;
	unsigned long long x=1;
	while(x<=num)
	{
		ans+=x;
		x<<=1;
	}
	return ans;
}

int main()
{
	unsigned long long int l,r;
	scanf("%llu %llu",&l,&r);
	printf("%llu",get(r)-get(l-1));
	return 0;
}