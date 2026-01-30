test = int(input())

for t in range(test):
  arr = input().split()
  x, y, n = int(arr[0]), int(arr[1]), int(arr[2])
  for i in range(1, n + 1):
    if i % x == 0 and i % y == 0:
      print("FizzBuzz")
    elif i % x == 0:
      print("Fizz")
    elif i % y == 0:
      print("Buzz")
    else:
      print(i)