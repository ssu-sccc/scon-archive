import sys

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    p = 0

    n = data[p]
    p += 1

    a = [0] * (n + 1)
    s = 0
    w = 0

    for i in range(1, n + 1):
        x = data[p]
        p += 1
        a[i] = x
        s += x
        w += i * x

    out = []

    def ask():
        if s % n != 0:
            out.append("No")
            return
        x = s // n
        target = x * n * (n + 1) // 2
        out.append("Yes" if w == target else "No")

    ask()

    q = data[p]
    p += 1

    for _ in range(q):
        i = data[p]
        x = data[p + 1]
        p += 2

        delta = x - a[i]
        s += delta
        w += i * delta
        a[i] = x

        ask()

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()