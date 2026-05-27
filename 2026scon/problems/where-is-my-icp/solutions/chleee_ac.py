from collections import Counter
N = int(input())
S = input()
M = int(input())
T = input()
need = Counter("ICPC")
need.subtract(Counter(S))
have = Counter(T)
for c in need:
    if need[c] > have[c]:
        print("m4us sad")
        break
else:
    print("m4us happy")
