from itertools import accumulate

def time_to_seconds(time):
    h, m, s = time.split(':')
    return int(h) * 3600 + int(m) * 60 + int(s)

ans = []
while(1):
    N = int(input())
    if N==0:
        break
    A = []
    for n in range(N):
        begin, end = input().split()
        begin = time_to_seconds(begin)
        end = time_to_seconds(end)
        A.append((begin,1))
        A.append((end,-1))
    A.sort()
    mx = 0
    cumsum = 0
    for _, x in A:
        cumsum += x
        mx = max(mx, cumsum)
    ans.append(mx)

for a in ans:
    print(a)