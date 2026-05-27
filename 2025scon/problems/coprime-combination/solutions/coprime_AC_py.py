import sys

def preprocess():
    isp = list(range(5050))
    for i in range(2, int(5050**0.5) + 1):
        if isp[i] == i:
            for j in range(i * i, 5050, i):  
                if isp[j] == j:  
                    isp[j] = i  

    cnt = [[0] * 5050 for _ in range(5050)]
    for i in range(2, 5050):
        cnt[i] = cnt[i - 1][:]  # 이전 행을 복사하여 초기화
        tmp = i
        while tmp > 1:
            prime = isp[tmp]
            cnt[i][prime] += 1
            tmp //= prime

    return cnt

def is_coprime(n1, r1, n2, r2, cnt):
    for i in range(2, 5000):
        if (cnt[n1][i] - cnt[n1 - r1][i] - cnt[r1][i] > 0 and 
            cnt[n2][i] - cnt[n2 - r2][i] - cnt[r2][i] > 0):
            return 0
    return 1

input = sys.stdin.read
data = input().split("\n")

T = int(data[0])
cnt = preprocess()
result = []

for i in range(1, T + 1):
    if not data[i].strip():
        continue
    n1, r1, n2, r2 = map(int, data[i].split())
    result.append(str(is_coprime(n1, r1, n2, r2, cnt)))

sys.stdout.write("\n".join(result) + "\n")