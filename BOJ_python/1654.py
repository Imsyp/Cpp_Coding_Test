import sys
input = sys.stdin.readline

K, N = map(int, input().split())
LAN = [int(input().strip('\n')) for _ in range(K)]
start, end = 1, max(LAN) 

while(start <= end):
    mid = (end + start) // 2
    total = 0
    
    for l in LAN:
        total += l // mid
        
    if(total >= N):         # 랜선 개수가 많음 -> 짧게 잘림 -> 최대 길이 찾아야 함: 단위를 키워야 함
        start = mid + 1
    else:                   # 랜선 개수가 적음 (조건에 부합하지 않음): 단위를 줄여야 함
        end = mid - 1       
print(end)