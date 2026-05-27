import sys

input = sys.stdin.readline

def solve():
    n = int(input())
    A = [-1] * (n + 1)
    c = 0

    same_idx = -1
    diff_idx = -1

    def ask(i: int) -> int:
        nonlocal c
        sys.stdout.write(f"? {i}\n")
        sys.stdout.flush()
        x = int(input())
        c += 1
        return x

    def ans():
        sys.stdout.write("! " + " ".join(map(str, A[1:])) + "\n")
        sys.stdout.flush()

    def flip():
        for i in range(1, n + 1):
            if A[i] != -1:
                A[i] ^= 1

    def rev():
        A[1:] = A[1:][::-1]

    def query_pair(i: int):
        nonlocal same_idx, diff_idx
        A[i] = ask(i)
        A[n - i + 1] = ask(n - i + 1)
        if A[i] ^ A[n - i + 1]:
            if diff_idx == -1:
                diff_idx = i
        else:
            if same_idx == -1:
                same_idx = i

    i = 1
    while i <= n - i + 1:
        if i < n - i + 1:
            query_pair(i)
        else:
            A[i] = ask(i)

        if c % 10 == 0:
            if same_idx == -1:
                op = ask(diff_idx)
                op = ask(diff_idx)
                if A[diff_idx] != op:
                    flip()
            elif diff_idx == -1:
                op = ask(same_idx)
                op = ask(same_idx)
                if A[same_idx] != op:
                    flip()
            else:
                op1 = ask(diff_idx)
                op2 = ask(same_idx)

                if A[same_idx] == op2 and A[diff_idx] != op1:
                    rev()
                elif A[same_idx] != op2 and A[diff_idx] != op1:
                    flip()
                elif A[same_idx] != op2 and A[diff_idx] == op1:
                    rev()
                    flip()

        i += 1

    ans()

if __name__ == "__main__":
    T = 1
    for _ in range(T):
        solve()