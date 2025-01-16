N = input()
numbers = list(map(int, input().split()))
DP = numbers
for idx, num in enumerate(numbers):
    if (idx == 0): 
        continue
    DP[idx] += max(0, DP[idx - 1])

print(max(DP))