from math import gcd as gcd
t=int(input())
for test in range(t):
    x,y=list(map(int,input().split(' ')))
    if(gcd(x,y)>1):
        print("NO")
    else:
        print("YES")
