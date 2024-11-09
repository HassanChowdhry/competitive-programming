n = int(input())
arr = input().split()
nums = [int(a) for a in arr]

stack = [nums[0]]

for num in nums[1:]:
  while stack and num > stack[-1]:
    stack.pop()
  
  while stack and num == stack[-1]:
    num += stack.pop()
  
  stack.append(num)

print(stack[0])