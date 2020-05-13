N, W = map(int, input().split())
vw = []
for n in range(N):
    v, w = map(int,input().split())
    vw.append((v,w))
dp = [[0]*(W+1) for _ in range(N+1)]
for n in range(N):
    vn ,wn = vw[n]
    for w in range(W+1):
        if w-wn >= 0:
            dp[n+1][w] = max(dp[n][w-wn] + vn, dp[n][w])
        else:
            dp[n+1][w] = dp[n][w]
print (dp[N][W])

# 配るDP
Wmax = 1000
N, W = map(int, input().split())
vw = []
for n in range(N):
    v, w = map(int,input().split())
    vw.append((v,w))
dp = [[0]*(W+Wmax+1) for _ in range(N+1)]
for n in range(N):
    vn ,wn = vw[n]
    for w in range(W+1):
        dp[n+1][w] = max(dp[n+1][w],dp[n][w])        
        dp[n+1][w+wn] = dp[n][w] + vn
print (dp[N][W])

# 配るDP
Wmax = 1000
N, W = map(int, input().split())
vw = []
for n in range(N):
    v, w = map(int,input().split())
    vw.append((v,w))
dp = [[0]*(W+Wmax+1) for _ in range(N+1)]
for n in range(N):
    vn ,wn = vw[n]
    for w in range(W+1)[::-1]:
        dp[n+1][w] = dp[n][w]    
        dp[n+1][w+wn] = max(dp[n][w] + vn,dp[n+1][w+wn])
print (dp[N][W])