arr = [True] * (1002)
arr[0] = False
arr[1] = False

for i in range(2, int(1001**(1/2)+1)):
    if(arr[i] == True):
        j = 2

        while((i * j) <= 1001):
            arr[i * j] = False
            j += 1

N = int(input())
M = list(map(int, input().split(" ")))

sum = 0

for i in range(N):
    if(arr[M[i]] == True):
        sum += 1

print(sum)