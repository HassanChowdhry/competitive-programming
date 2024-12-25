from collections import defaultdict
from typing import List

def subarraysDivByK(nums: List[int], k: int) -> int:
  seen = defaultdict(int)
  prefix = 0

  for num in nums:
      prefix += num
      mod = prefix % k
      print(mod)
      seen[mod] += 1

  res = 0
  for key in seen:
      val = seen[key]
      if key == 0:
          res += ((val * (val+1)) // 2)
      else:
          res += ((val * (val-1)) // 2)
  return res

n = int(input())
nums = input().split()
nums = [int(num) for num in nums]

print(subarraysDivByK(nums, n))
