from itertools import accumulate

def time_to_seconds(time):
    h, m, s = time.split(':')
    return int(h) * 3600 + int(m) * 60 + int(s)

ans = []
while(1):
    N = int(input())
    if N==0:
        break
    A = [0] * 86400
    for n in range(N):
        begin, end = input().split()
        begin = time_to_seconds(begin)
        end = time_to_seconds(end)
        A[begin] += 1
        A[end] -= 1
    cumsum = accumulate(A)
    ans.append(max(cumsum))

for a in ans:
    print(a)