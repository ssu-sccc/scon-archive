import sys

input = lambda: sys.stdin.readline().rstrip("\n")


def main():
    arr = list(map(int, input().split()))
    h = int(input())
    ans = float('inf')

    for i in range(8):
        if i == 0: continue
        rh = rl = 0
        for j in range(3):
            if i & (1 << j):
                rh += arr[j] // 2
                rl += arr[j] // 2
            else:
                rl += arr[j]
        if rh < h:
            ans = min(ans, rl)
    print(ans)


if __name__ == '__main__':
    main()
