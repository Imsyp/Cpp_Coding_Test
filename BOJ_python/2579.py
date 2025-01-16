N = int(input())
stairs = []

for i in range(N):
    stairs.append(int(input()))

if(N <= 2):
    print(sum(stairs))
    exit()
elif(N == 3):
    print(stairs[2] + max(stairs[0], stairs[1]))
    exit()
    
DP = stairs[:]
DP[0] = stairs[0]
DP[1] = stairs[0] + stairs[1]
DP[2] = stairs[2] + max(stairs[0], stairs[1])

for i in range(3, N):
    DP[i] = stairs[i] + max(DP[i - 3] + stairs[i - 1], DP[i - 2])

print(DP[N - 1])