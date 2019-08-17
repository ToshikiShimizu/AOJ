import queue

N = 100
INFTY = 1<<21
d = [None for i in range(N)]
M = [[None for i in range(N)] for j in range(N)]
def bfs(s):
    q = queue.Queue()
    q.put(s)
    for i in range(n):
        d[i] = INFTY
    d[s]=0
    while(not q.empty()):
        u = q.get()
        for v in range(n):
            if M[u][v]==0:
                continue
            if d[v] != INFTY:
                continue
            d[v] = d[u] + 1
            q.put(v)#
    
    for i in range(n):
        if d[i]==INFTY:
            tmp = -1
        else:
            tmp = d[i]
        print (str(i+1)+" "+str(tmp))

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
    bfs(0)