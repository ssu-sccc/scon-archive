v = [0 for _ in range(101)]
for _ in range(int(input())):
    a, b, c = map(int, input().split())
    v[a] += 1
    v[b] += 1
    v[c] += 1

ans = 0
for i in range(1, 101):
    for j in range(i + 1, 101):
        for k in range(j + 1, 101):
            v[i] += 1
            v[j] += 1
            v[k] += 1

            cur = {i, j, k}
            for prize_cut in range(100, 0, -1):
                if v[prize_cut] == 1:
                    if prize_cut in cur:
                        ans += 1
                    break

            v[i] -= 1
            v[j] -= 1
            v[k] -= 1

print(ans)
