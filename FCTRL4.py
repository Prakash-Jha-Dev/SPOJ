from sys import stdin

def get(val):
	while(val%10==0):
		val//=10
	return val%100

fact=[1]*11
for i in range(2,11):
	fact[i]=get(fact[i-1]*i)

def power(y):
	res=1
	base=8
	while(y>0):
		if(y%2==1):
			res=get(res*base)
		base=get(base*base)
		y//=2
	return res


for line in stdin:
	n=int(line)
	if(n<10):
		print(fact[n])
	else:
		t=n//10
		r=n%10
		s=get(power(t)*fact[r])
		print(s)