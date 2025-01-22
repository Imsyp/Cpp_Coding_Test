from collections import deque

vertices, edges, start = map(int, input().split())

# Matrix[i][j]: i번 vertex에 j번 vertex가 연결됐으면 1
Matrix = [[False for j in range(vertices + 1)] for i in range(vertices + 1)]

# Vertex 연결
for e in range(edges):
    e1, e2 = map(int, input().split())
    Matrix[e1][e2] = True
    Matrix[e2][e1] = True


"""
    DFS
    1. stack에 시작점 append()
    2. cur = stack.pop() 
    3. cur에 연결된 vertex 모두 stack에 append() (방문한 경우 제외)
    4. stack이 empty state에 도달할 때까지 2 ~ 3 반복
"""
def DFS(start):
    stack = [start]
    path = []
    visited = [False for i in range(vertices + 1)]
    
    while(stack):
        cur = stack.pop()
        if(visited[cur]):
            continue
        visited[cur] = True
        path.append(cur)
        for toEdge in range(vertices, 0, -1):
            if(Matrix[cur][toEdge] and not visited[toEdge]):
                stack.append(toEdge)
    return path
        
print(*DFS(start))

"""
    BFS
    1. queue에 시작점 enqueue()
    2. cur = queue.dequeue() (방문한 경우, 재수행)
    3. cur에 연결된 vertex 모두 queue에 enqueue() (방문한 경우 제외)
    4. queue가 empty state에 도달할 때까지 2 ~ 3 반복
"""
def BFS(start):
    path = []
    queue = deque([start])
    visited = [False for i in range(vertices + 1)]
    
    while(queue):
        cur = queue.popleft()
        if(visited[cur]):
            continue
        visited[cur] = True
        path.append(cur)
        for toEdge in range(1, len(Matrix[cur])):
            if(Matrix[cur][toEdge] and not visited[toEdge]):
                queue.append(toEdge)
    return path

print(*BFS(start))