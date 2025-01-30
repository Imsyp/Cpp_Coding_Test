import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

def dfs(start, numbers, visited):
    if(visited[start]):
        return 

    visited[start] = True
    dfs(numbers[start], numbers, visited)
    

cases = int(input().strip('\n'))
while(cases):
    number = input().strip('\n')
    numbers = list(map(int, input().split()))
    visited = [False for _ in range(len(numbers) + 1)]
    numbers = [ 0 ] + numbers

    result = 0
    for start in range(1, len(numbers)):
        if not (visited[start]):
            dfs(start, numbers, visited)
            result += 1
    print(result)
    cases -= 1