from sys import stdin
for line in stdin:
    n = int(line)
    print(n+max(0,n-2))
