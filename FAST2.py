def sum(n):
	n = 2**(n+1)-1
	return n%1298074214633706835075030044377087


n = int(input())
for x in range(n):
	y = int(input())
	print(sum(y))