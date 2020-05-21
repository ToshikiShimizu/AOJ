V, E = map(int, input().split())
INF = 10**10
cost = [[INF]*V for _ in range(V)]
for e in range(E):
    s, t, d = map(int,input().split())
    cost[s][t] = d

dp = [[-1] * V for _ in range(1<<V)]

def dfs(S, v, dp):
    if dp[S][v] != -1:
        return dp[S][v]
    if S==(1<<V)-1 and v==0:
        return 0

    res = INF
    for u in range(V):
        if S>>u & 1 == 0:
            res = min(res, dfs(S|1<<u, u, dp)+cost[v][u])
    dp[S][v] = res
    return res

ans = dfs(0, 0, dp)
if ans == INF:
    print(-1)
else:
    print (ans)