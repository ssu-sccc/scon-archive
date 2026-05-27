import sys

input = sys.stdin.readline

def ask(l: int, r: int) -> int:
    sys.stdout.write("? " + str(r - l + 1) + " " + " ".join(map(str, range(l, r + 1))) + "\n")
    sys.stdout.flush()
    return int(input())

def solve():
    n = int(input())

    l, r = 0, n
    while l + 1 < r:
        m = (l + r) >> 1
        if ask(1, m):
            r = m
        else:
            l = m

    L, R = 1, n + 1
    while L + 1 < R:
        M = (L + R) >> 1
        if ask(M, n):
            L = M
        else:
            R = M

    sys.stdout.write(f"! {r} {L}\n")
    sys.stdout.flush()

if __name__ == "__main__":
    solve()