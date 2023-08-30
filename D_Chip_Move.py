MOD = 998244353

def count_ways(n, k):
    dp = [0] * (n + 1)
    dp[0] = 1
    
    for i in range(1, n + 1):
        dp[i] = 2  # Initialize dp[i] with 2 (two ways to reach i: from i-1 and i-k)
        j = 1
        
        while j <= k and i - j >= 0:
            dp[i] += dp[i - j]
            dp[i] %= MOD
            j += 1
    
    return dp[1:]

# Input
n, k = map(int, input().split())

# Calculate and print the number of ways to reach each point modulo 998244353.
ways = count_ways(n, k)
print(*ways)
