N, Q = map(int, input().split())
A = list(map(int, input().split()))
X = list(map(int, input().split()))

def two_pointers(x):
    left = 0
    sm = 0
    ans = 0
    for right in range(N):
        sm += A[right]
        while(sm > x):
            sm -= A[left]
            left += 1
        ans += (right-left+1) # leftに対する条件を満たすパターン数
    return ans

for x in X:
    print(two_pointers(x))
