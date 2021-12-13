fact=[1]*101;
for i in range(1,101):
	fact[i]=fact[i-1]*i

n=int(input())
for i in range(n):
	x=int(input())
	print(fact[x])