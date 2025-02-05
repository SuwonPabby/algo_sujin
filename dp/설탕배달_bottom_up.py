import sys

input = sys.stdin.readline

N = int(input())
dp = [-2] * max(6, (N + 1))

dp[0] = -1
dp[1] = -1
dp[2] = -1
dp[3] = 1
dp[4] = -1
dp[5] = 1

if N <= 5:
    print(dp[N])
    sys.exit()

for i in range(6, N + 1):
    if max(dp[i - 3], dp[i - 5]) == -1:
        dp[i] = -1
    elif min(dp[i - 3], dp[i - 5]) == -1:
        dp[i] = max(dp[i - 3], dp[i - 5]) + 1
    else:
        dp[i] = min(dp[i - 3], dp[i - 5]) + 1

print(dp[N])
