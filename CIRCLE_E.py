import math
t=int(input())
for test in range(t):
    r=list(map(int,input().split(' ')))
    c1=(1/r[0] + 1/r[1]+ 1/r[2])
    c2=(1/(r[0]**2) + 1/(r[1]**2) + 1/(r[2]**2))
    x=c1+(math.sqrt(2*(c1**2) -2*c2))
    x=1/x
    print('%.10f'%x)
