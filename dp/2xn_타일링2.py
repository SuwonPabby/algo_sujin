import sys

N = int(input())

dp = [-1] * max(3, (N + 1))
dp[1] = 1
dp[2] = 3

if N <= 2:
    print(dp[N])
    sys.exit()

for i in range(3, N + 1):
    dp[i] = 2 * dp[i - 2] + dp[i - 1]

print(dp[N] % 10007)
