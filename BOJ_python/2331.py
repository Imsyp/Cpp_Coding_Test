import sys
input = sys.stdin.readline

visited = [False for _ in range(236197)]

A, P = map(int, input().split())

curNum = A
numbers = []
while not (visited[curNum]):
    numbers.append(curNum)
    visited[curNum] = True
    
    nextNum = 0
    while(curNum):
        nextNum += (curNum % 10) ** P
        curNum //= 10
        
    curNum = nextNum

for i, num in enumerate(numbers):
    if(num == curNum):
        print(i)
        break