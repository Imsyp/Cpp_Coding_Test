import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

cases = int(input().strip('\n'))
graph = []
visited = []

"""
    1. 현재 vertex의 group 저장
    2. 인접 노드 탐색
        - 방문 X: -group 전달
        - 방문 O
            - 같은 그룹인 경우 -> return false
"""
def dfs(v, group, graph, visited):
    visited[v] = group
    for adj in graph[v]:
        if(visited[adj] == 0):
            if not (dfs(adj, -group, graph, visited)):
                return False
        else:
            if(visited[adj] == group):
                return False
    
    return True

while(cases):
    V, E = map(int, input().split())
    graph = [[] for _ in range(V + 1)]
    visited = [0 for _ in range(V + 1)]    # -1, 0, 1
    
    for _ in range(E):
        e1, e2 = map(int, input().split())
        graph[e1].append(e2)
        graph[e2].append(e1)
    
    result = "YES"
    for v in range(1, V + 1):      
        # 미방문
        if(visited[v] == 0):
            if not (dfs(v, 1, graph, visited)):
                result = "NO"
    print(result)
    cases -= 1