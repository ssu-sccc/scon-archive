A, h = list(map(int, input().split())), int(input()) * 2
V = [sum(A[i] for i in range(3) if k>>i&1) for k in range(8)]
print(sum(A) - max(v for v in V if v < h) // 2)
