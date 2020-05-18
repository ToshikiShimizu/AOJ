import queue
N = int(input())

adj = [[]for i in range(N+1)]
depth = [-1] * (N+1)
for n in range(1,N+1):
    V = list(map(int,input().split()))
    for v in V[2:]:
        #print(n,v)
        adj[n].append(v)
    
q = queue.Queue()
q.put((1,0))
while(not q.empty()):
    x, d = q.get()
    if depth[x] != -1:
        continue
    depth[x] = d
    for next in adj[x]:
        if depth[next] == -1:
            q.put((next,d+1))

for i in range(1,N+1):
    print(i,depth[i])