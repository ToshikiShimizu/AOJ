import bisect
INF = 10**10
N = int(input())
dp = [INF] * (N)
for n in range(N):
    a = int(input())
    i = bisect.bisect_left(dp, a)
    dp[i] = a
print(bisect.bisect_left(dp, INF))