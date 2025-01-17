N = int(input())
DP = [0 for i in range(N + 1)]
if(N <= 4):
    if(N == 2):
        print(3)
        exit()
    elif(N == 4):
        print(11)
        exit()
    else:
        print(0)
        exit()
DP[2] = 3
DP[4] = 11
 
for i in range(6, N + 1, 2):
    DP[i] = (DP[i - 2] * DP[2]) + (sum(DP[:i - 2]) * 2) + 2


print(DP[N])