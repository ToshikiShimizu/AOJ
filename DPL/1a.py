N, M = map(int, input().split())
C = list(map(int,input().split()))
INF = 10**10
dp = [[INF]*(N+1) for _ in range(M+1)]
dp[0][0] = 0
for m in range(M):
    for n in range(N+1):
        if n-C[m]>=0:
            dp[m+1][n] = min(dp[m+1][n-C[m]]+1, dp[m][n])
        else:
            dp[m+1][n] = dp[m][n]
print (dp[M][N])