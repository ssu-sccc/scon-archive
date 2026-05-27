ints=lambda: list(map(int, input().split()))

n=int(input())
k=10**9
ans=0
for i in ints()[::-1]:
    k=min(i, k); ans+=k
print(ans)