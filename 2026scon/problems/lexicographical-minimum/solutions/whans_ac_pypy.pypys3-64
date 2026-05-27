import sys

def solve():
    input = sys.stdin.buffer.readline

    n = int(input())
    t = input().strip().decode()

    chars = []
    cnts = []

    s = 0
    while s < n:
        e = s
        c = t[s]
        while e < n and t[e] == c:
            e += 1
        chars.append(c)
        cnts.append(e - s)
        s = e

    m = len(chars)
    for i in range(1, m):
        if chars[i - 1] > chars[i]:
            cnts[i - 1] = 1
            
    cnts[m-1] = 1;

    ans = ''.join(chars[i] * cnts[i] for i in range(m))
    sys.stdout.write(ans + '\n')

if __name__ == "__main__":
    solve()