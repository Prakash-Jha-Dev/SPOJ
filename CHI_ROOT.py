from decimal import *

t=int(input())
for test in range(t):
    temp=input().split(' ')
    getcontext().prec=202
    
    n=Decimal(temp[0])
    x=Decimal(temp[1])
    ans=Decimal(Decimal(x).ln()/n).exp()
    ans=str(ans)
    temp=ans.split('.')
    temp=temp[0]+temp[1].rstrip('0')
    print(temp[:101])
