from collections import deque
inn = input().split()
n, m = inn
n, m = int(n), int(m)
graph = [[0] * m for _ in range(n)]
dp = [[-1] * m for _ in range(n)]

for i in range(n):
  thing = input().split()
  for j in range(m):
    graph[i][j] = int(thing[j])

res = [(0, 0, 0)]
queue = deque(res)
visit = set()

while queue:
  x, y, speed = queue.popleft()
  dp[x][y] = max(dp[x][y], speed)
  
  if (x, y) in visit:
    continue
  visit.add((x, y))
  
  i, j = x, y+1
  if i >= 0 and i < n and j >= 0 and j < m:
    res = graph[x][y] - graph[i][j] - 10 + speed
    if res >= 0:
      queue.append((i, j, res))
  
  i, j = x+1, y
  if i >= 0 and i < n and j >= 0 and j < m:
    res = graph[x][y] - graph[i][j] - 10 + speed
    if res >= 0:
      queue.append((i, j, res))
  
  i, j = x+1, y+1
  if i >= 0 and i < n and j >= 0 and j < m:
    res = graph[x][y] - graph[i][j] - 15 + speed
    if res >= 0:
      queue.append((i, j, res))

if dp[-1][-1] == -1:
  print("TOO SLOW")
else:
  print(dp[-1][-1])