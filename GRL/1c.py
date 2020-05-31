N, M = map(int, input().split())
INF = float('inf')
cost = [[INF]*N for _ in range(N)]
for n in range(N):
    cost[n][n] = 0
for m in range(M):
    a, b, t = map(int, input().split())
    cost[a][b] = t

for i in range(N): # 中継点
    for j in range(N): # 始点
        for k in range(N): # 終点
            cost[j][k] = min(cost[j][i]+cost[i][k], cost[j][k])

for n in range(N):
    if cost[n][n] < 0:
        print ('NEGATIVE CYCLE')
        exit()

for c in cost:
    c = [str(i).replace('inf','INF') for i in c]
    print(' '.join(c))