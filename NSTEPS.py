t=int(input())
for test in range(t):
    x,y=map(int,input().split())
    if(x==y or x==y+2):
        if(x%2==0):
            print(x+y)
        else:
            print(x+y-1)
    else:
        print("No Number")