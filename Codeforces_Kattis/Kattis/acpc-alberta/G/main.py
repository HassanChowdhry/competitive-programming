inn = input().split()
arr = input().split()
nums = [int(num) for num in arr]

n, s, m = inn
n = int(n)
s = int(s)
m = int(m)

def slide(d):
  l, r = 0, 0
  curr = 0
  N = len(nums)
  
  while r < N: 
    if (nums[r] >= d):
      r += 1
    else:
      r += 1
      l = r
      continue
  
    if (r - l) == s:
      curr += 1
      l = r
      continue
      
  return curr >= m

l, r = 0, max(nums)
while l < r:
  mid = (l + r + 1) // 2
  if slide(mid):
    l = mid
  else:
    r = mid - 1

print(l)

