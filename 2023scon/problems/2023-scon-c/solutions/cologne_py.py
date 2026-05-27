def main():
    N = int(input())
    *A, = map(int, input().split())
    for i in range(N-1):
        if A[i+1]-A[i] != A[1] - A[0]:
            print('NO')
            return
    print('YES')
    print(*A)
    print(*([0]*N))


if __name__ == '__main__':
    main()
