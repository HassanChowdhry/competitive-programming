import math
s = input()
while (s != "END"):
  cnt = 1
  x = s
  while True:
    nxt = str(len(x))
    if nxt == x: 
      print(cnt)
      break
    
    x = nxt
    cnt += 1
  s = input()
  