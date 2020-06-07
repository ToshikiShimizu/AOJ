import sys
sys.setrecursionlimit(10**7)

dxdy = ((0,1),(0,-1),(1,0),(-1,0),(-1,1),(1,-1),(1,1),(-1,-1))
ans = []
while(1):
    W, H = map(int, input().split())
    if (W==0 and H==0):
        break
    mp = []
    for h in range(H):
        line = input()
        line = line.split()
        line = [-int(l) for l in line]
        mp.append(line)
    def dfs(h,w):
        mp[h][w] = k
        for dx, dy in dxdy:
            nw = w + dx
            nh = h + dy
            if (0 <= nh < H and 0 <= nw < W):
                if (mp[nh][nw] == -1):
                    dfs(nh, nw)
    k = 0
    for h in range(H):
        for w in range(W):
            if mp[h][w] == -1:
                k += 1
                dfs(h,w)
    ans.append(k)
for a in ans:
    print(a)