import sys
from collections import deque

input = sys.stdin.readline

N, M, C, D = map(int, input().split())
k_list = list(map(int, input().split()))

# 초기 DP (0초)
dp_prev = [0] * (M + 1)

for t in range(N):
    dp_curr = [-float('inf')] * (M + 1)

    # 온도를 mod C 로 나눈 각 그룹별로 슬라이딩 윈도우 최대값 처리
    for mod in range(C):
        dq = deque()

        # mod 로 나눴을 때의 가능한 온도들을 순서대로 처리
        temps = [k for k in range(mod, M + 1, C)]
        len_temps = len(temps)

        left = 0
        for right in range(len_temps):
            curr_temp = temps[right]

            # 슬라이딩 윈도우의 크기 제한 (D 범위 내만 유지)
            while dq and temps[dq[0]] < curr_temp - D:
                dq.popleft()

            # dp_prev값이 큰 순서를 유지하며 deque에 추가
            while dq and dp_prev[temps[dq[-1]]] <= dp_prev[curr_temp]:
                dq.pop()

            dq.append(right)

            # dq[0]가 현재 curr_temp에서 올 수 있는 최대 dp_prev 값이 있는 온도
            max_prev = dp_prev[temps[dq[0]]]
            dp_curr[curr_temp] = max_prev + M - abs(k_list[t] - curr_temp)

    dp_prev = dp_curr  # 다음 초로 이동

# 최종 결과
print(max(dp_prev))
