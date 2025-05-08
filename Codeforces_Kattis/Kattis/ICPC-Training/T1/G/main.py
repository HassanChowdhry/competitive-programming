#! this does not work
nt, ns, dist = input().split()
nt, ns, dist = int(nt), int(ns), int(dist)

maxx = dist

dp = [[0] * maxx for _ in range(maxx)]

trees = []
for _ in range(nt):
  x, y = input().split()
  x, y = int(x), int(y)
  
  dp[x][y] = float("inf")
  
  trees.append((x, y))
  
for _ in range(ns):
  x, y = input().split()
  x, y = int(x), int(y)
  
  for i, j in trees:
    up = i - y
    hor = j + x
    if (hor < maxx):
      dp[up][hor] += 1

res = []

for i in range(dist):
  for j in range(dist):
    if dp[i][j] == ns:
      res.append((i, j))
  
n = len(res)

if n == 0:
  print("Impossible")
elif n >= 2:
  print("Ambiguous")
else:
  x, y = res[0]
  print(f'{x} {y}')
  
  
# K, B, G