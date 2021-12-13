t=int(input())
for test in range(t):
        y=input()
        s=input().split(' ')
        if(s[0].isdigit()==False):
                s[0]=str(int(s[4])-int(s[2]))
        else:
                if(s[2].isdigit()==False):
                        s[2]=str(int(s[4])-int(s[0]))
                else:
                        s[4]=str(int(s[0])+int(s[2]))
        print(s[0],"+",s[2],"=",s[4])
