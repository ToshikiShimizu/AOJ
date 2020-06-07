from collections import deque
dxdy = ((-1,0), (1,0), (0,-1), (0,1)) # タプルやリストで持っておくと便利

def solve(W,H,ver,hor):
    dist = [ [0]*W for _ in range(H)]
    dist[0][0] = 1
    q = deque()
    q.append((0,0)) # スタート地点をenqueue
    while(q):
        y, x = q.popleft()
        if y==H-1 and x==W-1:
            break
        else:
            for dx, dy in  dxdy:
                if (dx==-1 and ver[y][x]==0) or (dx==1 and ver[y][x+1] == 0) or (dy==-1 and hor[y][x]==0) or (dy==1 and hor[y+1][x]==0): # 通行可能か
                    if dist[y+dy][x+dx] == 0: # 未訪問か
                        q.append((y+dy,x+dx))
                        dist[y+dy][x+dx] = dist[y][x] + 1 # 距離を記録
    return dist[H-1][W-1]
ans = []
while(1):
    W, H = map(int,input().split())
    if W==0 and H==0:
        break
    ver = []
    hor = []
    hor.append([1]*W)
    for i in range(2*H-1):
        bar = list(map(int,input().split()))
        if i%2==0:
            ver.append([1]+bar+[1])
        else:
            hor.append(bar)
    hor.append([1]*(W+1))
    ans.append(solve(W,H,ver,hor))

for a in ans:
    print(a)


