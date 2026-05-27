import sys

def main():
    mod = 1_000_000_007
    N = 1_000_101
    
    n = int(sys.stdin.readline().strip())
    
    pw = [1] * (n + 1)
    dp = [0] * (n + 1)
    dp[1] = 24
    
    for s in range(1, n + 1):
        pw[s] = pw[s - 1] * 26 % mod
    
    for s in range(2, n + 1):
        dp[s] = (2 * pw[s - 1] % mod + (22 * dp[s - 1]) % mod) % mod
    
    print(dp[n])

if __name__ == "__main__":
    main()
