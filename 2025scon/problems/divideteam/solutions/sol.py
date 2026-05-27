def main():
    n = int(input())
    A = [0] + list(map(int, input().split())) 
    B = [0] + list(map(int, input().split()))
    S = [0] * (n + 1)

    for i in range(1, n + 1):
        S[i] = S[i - 1] + B[i] * (1 if A[i] else -1)

    P = []
    for i in range(1, n):
        P.append(S[n] - S[i])

    cnt = 1
    ans = S[n]
    for i in range(n - 2, -1, -1):
        if P[i] > 0:
            cnt += 1
            ans += P[i]

    print(cnt, ans)

if __name__ == "__main__":
    main()
