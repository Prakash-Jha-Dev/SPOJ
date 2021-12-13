from math import gcd as gcd
n=input()
a=list(map(int,input().split(' ')))
x=1
for z in a:
    x=x*z
n=input()
b=list(map(int,input().split(' ')))
y=1
for z in b:
    y=y*z
s=str(gcd(x,y))
if(len(s)<10):
    print(s)
else:
    print(s[len(s)-9:])
