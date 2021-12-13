from math import gcd as gcd
t=int(input())
for test in range(t):
    x,y=[int(x) for x in input().split(' ')]
    x=gcd(x,y)
    print(x)
