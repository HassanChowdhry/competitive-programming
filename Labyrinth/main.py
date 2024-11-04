from collections import deque
x, y = input().split()
x, y = int(x), int(y)

arr = [list(input()) for _ in range(x)]
# print(arr)

def bfs(i, j):
  queue = deque()
  queue.append((i, j, ""))
  
  while queue:
    r, c, s = queue.popleft()
    
    # print(r, c, arr[r][c], s)
    
    if arr[r][c] == 'B':
      return s
    arr[r][c] = '#'
    
    if (r - 1 >= 0 and c >= 0 and r - 1 < x and c < y) and arr[r-1][c] != '#':
      queue.append((r-1, c, s+'U'))
    if (r + 1 >= 0 and c >= 0 and r + 1 < x and c < y) and arr[r+1][c] != '#':
      queue.append((r+1, c, s+'D'))
    if (r >= 0 and c - 1 >= 0 and r < x and c - 1 < y) and arr[r][c-1] != '#':
      queue.append((r, c-1, s+'L'))
    if (r >= 0 and c + 1 >= 0 and r < x and c + 1 < y) and arr[r][c+1] != '#':
      queue.append((r, c+1, s+'R'))
    
  return ""

res = ""
# print(len(arr))
# print(len(arr[0]))
for i in range(x):
  for j in range(y):
    if arr[i][j] == 'A':
      res = bfs(i, j)
      # print(res)
      break

# print(res)

if not res:
  print("NO")
else:
  print("YES")
  print(len(res))
  print(res)