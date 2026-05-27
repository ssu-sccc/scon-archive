import sys
input=sys.stdin.readline
ints=lambda: list(map(int, input().split()))
n, m=ints(); m-=1
arr=ints()
idx=[0]*n
for i in range(n):
    idx[arr[i]-1]=i
L=R=0
mod=0
for i in range(m):
    R+=(idx[i]-mod)%n
    mod=idx[i]
    #print(R)
mod=0
for i in range(n-1, m-1, -1):
    L+=(idx[i]-mod)%n
    mod=idx[i]
    #print(L)
if R>L: print("CCW")
elif R<L: print("CW")
else: print("EQ")