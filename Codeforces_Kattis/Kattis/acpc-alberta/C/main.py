inn = input().split()
N, P = inn
N = int(N)
P = int(P)
arr = [[0]* N for _ in range(P)]

for i in range(N):
  st = input().split()
  for j in range(P):
    arr[j][i] = (int(st[j]), i)

for i in range(len(arr)):
  arr[i] = sorted(arr[i])
  
# print(arr)
mp = {}
count = 0

for i in range(P):
  satisfactory = True
  path = str(arr[i][0][1])
  for j in range(1, N):
    # print(arr[i][j][0], arr[i][j-1][0])
    if arr[i][j][0] <= arr[i][j-1][0]:
      satisfactory = False
      break
    path += str(arr[i][j][1])

  if satisfactory:
    count += 1
    # print(path)
    mp[path] = 1
  
print(len(mp))  
# print(arr)