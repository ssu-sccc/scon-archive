def main():
    N = int(input())
    A = [0, 1]
    while len(A) != N:
        A.append(A[-1] + A[-2])
    x = sum(A) // 2
    y = sum(A) // 2
    a = []
    b = []
    for i in range(N-1, -1, -1):
        if x >= A[i]:
            x -= A[i]
            a.append(i+1)
        elif y >= A[i]:
            y -= A[i]
            b.append(i+1)
    print(len(a))
    print(*a)
    print(len(b))
    print(*b)


if __name__ == '__main__':
    main()
