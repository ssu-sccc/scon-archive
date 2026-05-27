import sys
input = sys.stdin.readline

L = list(map(int, input().split()))
H = int(input())

def solve(idx, t, H):
    if idx == 3:
        return t if 1 <= H else 600
    return min(solve(idx + 1, t + L[idx], H), solve(idx + 1, t + L[idx] // 2, H - L[idx] // 2))

print(solve(0, 0, H))