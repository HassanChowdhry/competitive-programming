from heapq import heapify, heappop, heappush
inp = input().split()

inp = [int(i) for i in inp]

n = inp[0]
nums = inp[1:]

def f(n, array):
  res = []
  minheap, maxheap = [], []
  heapify(minheap), heapify(maxheap)
  for num in array[1:]:
    heappush(minheap, num)
    
  visitright = set()
  
  for num in array:
    
    visitright.add(num)
    while minheap and minheap[0] in visitright:
      heappop(minheap)
    
    left = not maxheap or num > -maxheap[0]
    right = not minheap or num < minheap[0]

    # print(left, right, num, minheap, maxheap)
    if left and right:
      res.append(num)
    
    heappush(maxheap, -num)
  return res

res = f(n, nums)
strr = ""
j = 0
for i in res:
  strr += f"{i} "
  j += 1
  if j == 100: break

if len(res) == 0:
  print(len(res))
else:
  print(f'{len(res)} {strr}')