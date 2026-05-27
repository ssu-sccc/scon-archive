import sys

def calc(t: str, start: int) -> int:
    cnt = 0
    prev = False
    for i, ch in enumerate(t):
        expected = chr(48 + (start ^ (i & 1)))  # '0' or '1'
        cur = (ch != expected)
        if cur and not prev:
            cnt += 1
        prev = cur
    return cnt

def solve():
    input = sys.stdin.buffer.readline
    n = int(input())
    t = input().strip().decode()
    sys.stdout.write(str(min(calc(t, 0), calc(t, 1))) + '\n')

if __name__ == "__main__":
    solve()