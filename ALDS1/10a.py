N = 45
dp = [0] * N
dp[0] = dp[1] = 1
for i in range(N-2):
    dp[i+2] = dp[i] + dp[i+1]
n = int(input())
print (dp[n])