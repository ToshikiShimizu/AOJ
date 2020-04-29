N = int(input())
n = N
ans = []
for i in range(2,int(N**0.5)+1):
    while(n%i==0):
        n //= i
        ans.append(i)
if n!=1:
    ans.append(n)
ans = [str(a) for a in ans]
ans = str(N)+": " + " ".join(ans)
print (ans)
