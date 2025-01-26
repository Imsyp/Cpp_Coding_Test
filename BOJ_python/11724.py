import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

vertices, edges = map(int, input().split())
graph = [[] for _ in  range(vertices + 1)]
visited = [False for _ in range(vertices + 1)]

for _ in range(edges):
    e1, e2 = map(int, input().split())
    graph[e1].append(e2)
    graph[e2].append(e1)

def dfs(curPoint):
    if visited[curPoint]:
        return
    visited[curPoint] = True

    for vertex in graph[curPoint]:
        if(visited[vertex]):
            continue
        dfs(vertex)

count = 0
for vertex in range(1, vertices + 1):
    if not visited[vertex]:
        count += 1
        dfs(vertex)

print(count)