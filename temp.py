import sys

input = sys.stdin.readline

N = int(input())
seq = list(map(int, input().split()))
dp = [0] * (N + 1)

if N == 1:
    print(1)

elif N == 2:
    print(2 if seq[0] != seq[1] else 1)

elif N == 3:
    if (seq[0] == seq[1] and seq[1] == seq[2]) or (seq[0] + seq[2] == seq[1]):
        print(2)
    else:
        print(3)

else:
    dp[1] = 1
    dp[2] = 2 if seq[0] != seq[1] else 1
    if (seq[0] == seq[1] and seq[1] == seq[2]) or (seq[0] + seq[2] == seq[1]):
        dp[3] = 2
    else:
        dp[3] = 3

    for i in range(4, N + 1):
        dp[i] = dp[i - 1] + 1
        if seq[i - 1] == seq[i - 2]:
            dp[i] = min(dp[i], dp[i - 2] + 1)
        else:
            dp[i] = min(dp[i], dp[i - 2] + 2)

        if (seq[i - 3] == seq[i - 2] and seq[i - 2] == seq[i - 1]) or (
            seq[i - 3] + seq[i - 1] == seq[i - 2]
        ):
            dp[i] = min(dp[i], dp[i - 3] + 2)
        else:
            dp[i] = min(dp[i], dp[i - 3] + 3)

    print(dp)
