N = int(input())
dp = [[0]*N for _ in range(N)]
R = []
for n in range(N):
    r, c = map(int,input().split())
    R.append(r)
R.append(c)
INF = 10**10
for l in range(1,N):
    for i in range(N-l):
        j = i+l
        dp[i][j] = INF
        for k in range(i,j):
            dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+R[i]*R[k+1]*R[j+1])
print (dp[0][-1])