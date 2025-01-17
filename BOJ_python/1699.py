import math

N = int(input())
DP = [i for i in range(N + 1)]
DP[0] = 0

for i in range(1, N + 1):
    maxPow = int(i**(1/2))
    for idx in range(1, maxPow + 1):
        DP[i] = min(DP[i], DP[i - idx**2] + 1)

print(DP[N])