import sys

def solve():
    n = int(sys.stdin.readline())
    lim = 2 * n

    composite = [False] * (lim + 1)
    for s in range(2, lim + 1):
        if not composite[s]:
            if s * s <= lim:
                for e in range(s * s, lim + 1, s):
                    composite[e] = True

    k = 0
    for s in range(n + 1, lim + 1):
        if not composite[s]:
            k = s
            break

    S = [0] * (n + 1)
    for s in range(1, n + 1):
        S[s] = 2 * k * s + (s * s) % k

    ans = [str(S[s] - S[s - 1]) for s in range(1, n + 1)]
    sys.stdout.write(" ".join(ans) + "\n")

solve()