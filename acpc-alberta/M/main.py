inn = input().split()
arr = input().split()
N, W = inn
N = int(N)
W = int(W)

nums = [int(num)*2 for num in arr]
curr, res = 0, 0

for i in range(N):
  tmins = W * 60
  curr = 0
  for j in range(i, N):
    tmins -= nums[j]
    if tmins < 0:
      break
    curr += 1
    res = max(curr, res)

print(res)
    
