N = int(input())
adj = [[] for i in range(N)]
for n in range(N):
    V = list(map(int, input().split()))
    for v in V[2:]:
        adj[n].append(v-1)
d = [0] * N
f = [0] * N

def dfs(v, t):
    t+=1
    d[v] = t
    for next in adj[v]:
        if d[next] == 0:
            t = dfs(next, t)
    t+=1
    f[v] = t
    return t

t = 0
for n in range(N):
    if d[n]==0:
        t = dfs(n,t)
    print (n+1,d[n],f[n])

