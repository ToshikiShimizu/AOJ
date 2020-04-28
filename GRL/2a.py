import heapq
V, E = map(int, input().split())
adj = [ [] for v in range(V)]
for e in range(E):
    s, t, w = map(int, input().split())
    adj[s].append((t,w))
    adj[t].append((s,w))

visited = [0] * V
pq = []
for t, w in adj[0]:
    heapq.heappush(pq, (w, t))
visited[0] = 1

ans = 0
while(pq):
    w, t = heapq.heappop(pq)
    if visited[t]:
        continue
    visited[t] = 1
    ans += w
    for s, w in adj[t]:
        if visited[s]==0:
            heapq.heappush(pq, (w, s))
print (ans)