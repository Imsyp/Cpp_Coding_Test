import sys
input = sys.stdin.readline

N, M = map(int, input().split())
trees = list(map(int, input().split()))

begin = min(trees)
end = max(trees)

while(begin <= end):
    middle = (begin + end) // 2
    total = sum([tree - middle for tree in trees if (tree >= middle)])
    if(total < M):
        end = middle - 1
    else:
        begin = middle + 1

print(end)