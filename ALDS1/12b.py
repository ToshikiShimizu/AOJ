import heapq
INF = 10**10

V, E, r = map(int,input().split())
adj = [[] for i in range(V)]

for e in range(E):
    s, t, d = map(int,input().split())
    adj[s].append((t,d))
    #adj[t].append((s,d))

dists  = [INF for i in range(V)]
dists[r] = 0
pq = [(0, r)]
while(pq):
    d, node = heapq.heappop(pq)
    #print (d,node)
    if (d > dists[node]):#探索の対象にする必要があるか確認
        continue
    for next, cost in adj[node]:
        if d + cost < dists[next]:
            dists[next] = d + cost
            heapq.heappush(pq, (dists[next],next))
for d in dists:
    if d == INF:
        print ('INF')
    else:
        print (d)