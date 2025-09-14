n = int(input())
n-=1


l = 3
f = 5
lcm = 15

x = n // 5
x = ((x * (x + 1)) // 2)
x*=5

y = n // 3
y = ((y * (y + 1)) // 2)
y*=3

z = n // 15
z = ((z * (z + 1)) // 2)
z*=15

res = (x + y - z)
print(res)

# print(1e18)