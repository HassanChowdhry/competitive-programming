seq = input()
top = 2 ** 47

pow2 = []
p = set()
for i in range(2, 61):
  n = 2 ** i
  pow2.append(n)
  p.add(n)

# print(pow2)
mp = {}
def f(seq):
  if seq[-1] == 'E':
    return False
  for i in range(len(seq) - 1):
    if seq[i] == 'O' and seq[i] == seq[i+1]:
      return False
    if seq[i] != 'E' and seq[i] != 'O':
      return False
  return True

arr = seq[::-1]
# print(arr)
def dfs(arr, p, pow2):
  res = 0
  
  for i in range(len(pow2)):
    num = pow2[i]
    # print(num)
    thing = True
    
    for i in range(len(arr)):
      a = arr[i]
      if num == 1:
        thing = False
        break
      
      if a == 'O':
        num -=1
        if num % 3 != 0:
          thing = False
          break
        num /= 3
      else:
        num *= 2
      
      if num in p:
        break
    
    if thing:
      thing = False
      res = num
      break
    
  return int(res)

if not f(seq):
  print("INVALID")
else:
  res = dfs(arr, p, pow2)
  if res == 0:
    print("INVALID")
  else:
    print(res)