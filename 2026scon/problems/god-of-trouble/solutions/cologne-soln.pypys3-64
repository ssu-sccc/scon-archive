import sys

input = lambda: sys.stdin.readline().rstrip("\n")


def main():
    n = int(input())

    lst = [tuple([None] * n)]

    def jitter():
        nonlocal lst
        (v,) = lst
        v = list(v)
        for i in range(n):
            if v[i] is None or v[n - i - 1] is None:
                v[i] = None
        r = [None if x is None else 1 - x for x in v]
        lst = list({tuple(v), tuple(reversed(v)), tuple(r), tuple(reversed(r))})

    for t in range(1333):
        if t % 10 == 0:
            jitter()

        if len(lst) > 1:
            for i in range(n):
                idxs = set(v[i] for v in lst)
                if len(idxs) != 1:
                    print('?', i + 1, flush=True)
                    resp = int(input())
                    lst = [v for v in lst if v[i] == resp]
                    break
        else:
            for i in range(n):
                for j in [i, n - i - 1]:
                    if lst[0][j] is None:
                        print('?', j + 1, flush=True)
                        resp = int(input())
                        rr = list(lst[0])
                        rr[j] = resp
                        lst[0] = tuple(rr)
                        break
                else:
                    continue
                break
            else:
                print('!', *lst[0], flush=True)
                return


if __name__ == '__main__':
    main()
