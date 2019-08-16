N = 100
WHITE = 0
GRAY = 1
BLACK = 2

color = [None for i in range(N)]
d = [None for i in range(N)]
f = [None for i in range(N)]
nt = [None for i in range(N)]
M = [[None for i in range(N)] for j in range(N)]

def next(u):
    for v in range(nt[u],n):
        nt[u] = v + 1
        if M[u][v]:
            return v
    return -1

def dfs_visit(r,tt):
    for i in range(n):
        nt[i] = 0
    S =[] # using a list as stack
    S.append(r)
    color[r] = GRAY
    tt+=1
    d[r] = tt
    while(bool(S)):
        u = S[-1]
        v = next(u)
        if v!=-1:
            if color[v]==WHITE:
                color[v] = GRAY
                tt+=1
                d[v] = tt 
                S.append(v)
        else:
            S.pop()
            color[u]=BLACK
            tt+=1
            f[u] = tt
    return tt

def dfs():
    for i in range(n):
        color[i] = WHITE
        nt[i] = 0
    
    tt = 0
    for u in range(n):
        if color[u] == WHITE:
            tt = dfs_visit(u,tt)
    for i in range(n):
        print (str(i+1) + " " + str(d[i]) + " " + str(f[i]))

if __name__=="__main__":
    n = int(input())
    for i in range(n):
        for j in range(n):
            M[i][j] = 0
    for i in range(n):
        ls  = list(map(int,input().split()))
        u = ls[0]
        k = ls[1]
        u-=1
        for j in range(k):
            v = ls[2+j]
            v -= 1
            M[u][v] = 1
    dfs()