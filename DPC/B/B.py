test = int(input())

for t in range(test):
  arr = input().split()
  arr = [int(n) for n in arr]
  arr.sort()
  s = input().strip()
  
  for i in range(3):
    if s[i] == 'C':
      print(arr[2], end=" ")
    elif s[i] == 'B':
      print(arr[1], end=" ")
    else:
      print(arr[0], end=" ")
  
  print()


