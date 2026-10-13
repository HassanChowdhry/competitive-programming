from functools import cache

people,weight = [int(i) for i in input().split()]
weights = [int(i) for i in input().split()]
weights.sort(reverse = True)

@cache
def dp(r, depth):
  

print(dp(tuple(weights),weight,weight,0))