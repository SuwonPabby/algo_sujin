import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**9)

N = int(input())
dp = [-2] * (N + 1)


def get_dp(n):
    if n < 3:
        return -1
    if n == 4:
        return -1
    if n == 3:
        return 1
    if n == 5:
        return 1

    if dp[n - 3] == -2:
        dp[n - 3] = get_dp(n - 3)
    if dp[n - 5] == -2:
        dp[n - 5] = get_dp(n - 5)

    if max(dp[n - 3], dp[n - 5]) == -1:
        dp[n] = -1
    elif min(dp[n - 3], dp[n - 5]) == -1:
        dp[n] = max(dp[n - 3], dp[n - 5]) + 1
    else:
        dp[n] = min(dp[n - 3], dp[n - 5]) + 1

    return dp[n]


print(get_dp(N))
