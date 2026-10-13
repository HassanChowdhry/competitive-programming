branch = int(input())

mp = [-1] * 1001
x = input()
while x != "-1":
  x = x.split()
  x = [int(i) for i in x]
  a = x[0]
  for b in x[1:]:
    mp[b] = a

  if mp[a] == -1:
    mp[a] = 0
  x = input()

curr = branch
while curr != 0:
  print(curr, end = " ")
  curr = mp[curr]