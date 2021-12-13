t=int(input())
for test in range(t):
    x,y=input().split(' ')
    x=x[::-1]
    y=y[::-1]
    z=str(int(x)+int(y))
    z=z.strip('0')
    z=z[::-1]
    print(z)
              