inp = input().split()
x, y = input().split()

array = [int(i) for i in inp]

avg = 0
for i in range(0, len(array), 2):
  avg += (array[i] * array[i+1])

avg //= 5
x = int(x)
y = int(y)

print((avg * x) // y)

