import sys
from collections import defaultdict

def solve():
    input_data = sys.stdin.read().split()
    
    N = int(input_data[0])
    M = int(input_data[1])
    Q = int(input_data[2])
    
    MAX_SIZE = 101010
    
    A = [0] * MAX_SIZE
    DD = [0] * MAX_SIZE
    G = [[] for _ in range(MAX_SIZE)]
    D = [defaultdict(int) for _ in range(MAX_SIZE)]
    
    idx = 3
    
    for _ in range(M):
        u = int(input_data[idx])
        v = int(input_data[idx+1])
        idx += 2
        
        G[u].append(v)
        G[v].append(u)
        DD[u] += 1
        DD[v] += 1
        
    for i in range(1, N + 1):
        for j in G[i]:
            D[i][DD[j]] += 1
            
    out = []
    for _ in range(Q):
        op = int(input_data[idx])
        if op == 1:
            u = int(input_data[idx+1])
            x = int(input_data[idx+2])
            idx += 3
            
            for d, cnt in D[u].items():
                A[d] += x * cnt
        else:
            d = int(input_data[idx+1])
            idx += 2
            out.append(str(A[d]))
            
    sys.stdout.write('\n'.join(out) + '\n')

if __name__ == '__main__':
    solve()