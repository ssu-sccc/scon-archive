n = int(input())
a = [*input().split()]
for i in range(2, n) :
    if int(a[i])-int(a[i-1]) != int(a[1])-int(a[0]):
        print("NO")
        exit(0)
print("YES")
print(" ".join(a))
print(" ".join("0"*n))
