import sys

day_count, threshold = map(int, sys.stdin.readline().split())
record = list(map(int, sys.stdin.readline().split()))

ans = 0

stress = 0
for delta in record:
    stress = max(0, stress + delta)
    if stress >= threshold:
        ans += 1

print(ans)