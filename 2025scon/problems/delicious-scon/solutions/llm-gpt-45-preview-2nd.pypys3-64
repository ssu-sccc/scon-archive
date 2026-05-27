import sys
from collections import deque

input = sys.stdin.readline

N, M, C, D = map(int, input().split())
k_list = list(map(int, input().split()))

dp_prev = [0] * (M + 1)

for t in range(N):
    dp_curr = [-float('inf')] * (M + 1)

    for mod in range(C):
        # mod C로 나눈 나머지 그룹 별로 처리
        temps = [k for k in range(mod, M + 1, C)]
        len_temps = len(temps)

        # 방향 1: 왼쪽 → 오른쪽
        dq = deque()
        ptr = 0  # 윈도우의 왼쪽 끝
        for i in range(len_temps):
            curr_temp = temps[i]

            # 윈도우 범위 유지(curr_temp - D <= temps[ptr])
            while ptr < len_temps and temps[ptr] < curr_temp - D:
                if dq and dq[0] == ptr:
                    dq.popleft()
                ptr += 1

            while dq and dp_prev[temps[dq[-1]]] <= dp_prev[curr_temp]:
                dq.pop()
            dq.append(i)

            max_prev = dp_prev[temps[dq[0]]]
            dp_curr[curr_temp] = max(dp_curr[curr_temp], max_prev + M - abs(k_list[t] - curr_temp))

        # 방향 2: 오른쪽 → 왼쪽
        dq = deque()
        ptr = len_temps - 1  # 윈도우의 오른쪽 끝
        for i in reversed(range(len_temps)):
            curr_temp = temps[i]

            # 윈도우 범위 유지(temps[ptr] <= curr_temp + D)
            while ptr >= 0 and temps[ptr] > curr_temp + D:
                if dq and dq[0] == ptr:
                    dq.popleft()
                ptr -= 1

            while dq and dp_prev[temps[dq[-1]]] <= dp_prev[curr_temp]:
                dq.pop()
            dq.append(i)

            max_prev = dp_prev[temps[dq[0]]]
            dp_curr[curr_temp] = max(dp_curr[curr_temp], max_prev + M - abs(k_list[t] - curr_temp))

    dp_prev = dp_curr

print(max(dp_prev))