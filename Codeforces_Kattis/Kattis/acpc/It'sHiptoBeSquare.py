from math import sqrt

def solution(N: int) -> int:
  return int(sqrt(N + 1) - 1 ) // 2

n = int(input())

for _ in range(n):
  N = int(input())
  print(solution(N))