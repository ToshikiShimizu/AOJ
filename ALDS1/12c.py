import heapq
MAX = 10000
INFTY = 1<<20
WHITE = 0
GRAY = 1
BLACK = 2


def dijkstra(n, adj):
    PQ = []
    color = [None for i in range(n)]
    d = [None for i in range(n)]
    for i in range(n):
        d[i] = INFTY
        color[i] = WHITE
    d[0] = 0
    heapq.heappush(PQ,(0,0))
    color[0] = GRAY
    while(len(PQ)>0):
        f = heapq.heappop(PQ)
        u = f[1]
        color[u] = BLACK
        if (d[u] < f[0]):
            continue
        for j in range(len(adj[u])):
            v = adj[u][j][0]
            if color[v]==BLACK:
                continue
            if (d[v]>d[u]+adj[u][j][1]):
                d[v] = d[u] + adj[u][j][1]
                heapq.heappush(PQ,(d[v],v))
                color[v] = GRAY
    for i in range(n):
        if d[i] == INFTY:
            tmp = -1
        else:
            tmp = d[i]
        print (str(i)+" "+str(tmp))
if __name__=="__main__":
    adj = [[] for i in range(MAX)]
    n = int(input())
    for i in range(n):
        ls  = list(map(int,input().split()))
        u = ls[0]
        k = ls[1]
        for j in range(k):
            adj[u].append([ls[2+2*j],ls[2+2*j+1]])
    dijkstra(n, adj)
