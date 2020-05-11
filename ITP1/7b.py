from itertools import combinations
nx = []
while(1):
    n, x = map(int,input().split())
    if n==0 and x==0:
        break
    nx.append((n,x))

for n,x in nx:
    cnt = 0
    for c in list(combinations(range(1,n+1),3)):
        if sum(c)==x:
            cnt += 1
    print (cnt)