import bisect
N = input()
INF = 10**10
S = list(map(int,input().split())) + [INF]
A = input()
T = list(map(int,input().split()))
ans = 0
for t in T:
    i = bisect.bisect_left(S, t)
    if (S[i] == t):
        ans += 1
print(ans)