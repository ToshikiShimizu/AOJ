from itertools import product
n = int(input())
A = list(map(int, input().split()))
q = int(input())
M = list(map(int, input().split()))

create = [0] * 40001

for p in product([0,1], repeat=n):
    sm = 0
    for i in range(n):
        if p[i]==1:
            sm += A[i]
    create[sm] = 1

for m in M:
    if create[m]:
        print('yes')
    else:
        print ('no')
        
