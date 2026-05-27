import sys
input = sys.stdin.readline

N = int(input())
T = input().strip()

CJS = 0
JCS = 0

for i in range(N):
    for j in range(i + 1, N + 1):
        if (i == 0 or T[i - 1] == 'S') and T[j - 1] == 'S':
            S = T[i:j]

            if 'SC' in S or 'SJ' in S or 'SS' in S:
                continue

            chk1 = 'CJ' in S
            chk2 = 'JC' in S

            if chk1 and not chk2:
                CJS += 1
            elif not chk1 and chk2:
                JCS += 1

print(CJS)
print(JCS)