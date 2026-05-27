# 세그먼트 트리 구현
class SegmentTree:
    def __init__(self, size):
        self.size = size
        self.tree = [-float('inf')] * (4 * size)
    
    def update(self, node, start, end, idx, val):
        if idx < start or idx > end:
            return
        if start == end:
            self.tree[node] = val
            return
        mid = (start + end) // 2
        self.update(node * 2, start, mid, idx, val)
        self.update(node * 2 + 1, mid + 1, end, idx, val)
        self.tree[node] = max(self.tree[node * 2], self.tree[node * 2 + 1])
    
    def query(self, node, start, end, left, right):
        if left > end or right < start:
            return -float('inf')
        if left <= start and end <= right:
            return self.tree[node]
        mid = (start + end) // 2
        return max(self.query(node * 2, start, mid, left, right),
                  self.query(node * 2 + 1, mid + 1, end, left, right))

def solve():
    # 입력 받기
    N, M, C, D = map(int, input().split())
    k = [0]  # 0초에는 최적 온도가 없으므로 더미값 추가
    k.extend(list(map(int, input().split())))
    
    max_result = -float('inf')
    
    # 각 나머지 r에 대해 별도의 DP 실행
    for r in range(C):
        # 나머지 r에 대해 가능한 온도 목록
        temps = []
        for j in range((M - r) // C + 1):
            temp = r + j * C
            if 1 <= temp <= M:
                temps.append(temp)
        
        if not temps:  # 가능한 온도가 없는 경우
            continue
        
        # dp[t][i] = t초에 온도가 temps[i]일 때 얻을 수 있는 최대 맛
        dp = [[-float('inf')] * len(temps) for _ in range(N + 1)]
        
        # 초기 상태: 0초에는 맛이 0, 어떤 온도든 선택 가능
        seg_tree = SegmentTree(len(temps))
        for i in range(len(temps)):
            dp[0][i] = 0
            seg_tree.update(1, 0, len(temps) - 1, i, 0)
        
        # 1초부터 N초까지
        for t in range(1, N + 1):
            new_seg_tree = SegmentTree(len(temps))
            
            for i in range(len(temps)):
                temp = temps[i]
                taste_increase = M - abs(k[t] - temp)
                
                # 이전 시간에서 현재 온도로 전이 가능한 범위 계산
                min_i = max(0, i - D // C)
                max_i = min(len(temps) - 1, i + D // C)
                
                if t == 1:  # 첫 시간은 모든 온도에서 시작 가능
                    dp[t][i] = taste_increase
                else:
                    # 구간 최대값 쿼리 (현재 온도와 같은 이전 온도는 제외)
                    max_prev = -float('inf')
                    if min_i <= i - 1:
                        max_prev = max(max_prev, seg_tree.query(1, 0, len(temps) - 1, min_i, i - 1))
                    if i + 1 <= max_i:
                        max_prev = max(max_prev, seg_tree.query(1, 0, len(temps) - 1, i + 1, max_i))
                    
                    if max_prev != -float('inf'):
                        dp[t][i] = max_prev + taste_increase
                
                if dp[t][i] != -float('inf'):
                    new_seg_tree.update(1, 0, len(temps) - 1, i, dp[t][i])
            
            seg_tree = new_seg_tree
        
        # r 나머지에서 시작하는 경우의 최대 맛
        r_max = -float('inf')
        for i in range(len(temps)):
            r_max = max(r_max, dp[N][i])
        
        if r_max != -float('inf'):
            max_result = max(max_result, r_max)
    
    return max_result

print(solve())