import sys

curr = sys.stdin.readline().rstrip()
dest = sys.stdin.readline().rstrip()

def solve(curr,dest):
    if curr == dest:
        print('Keep going straight')
        return
    arr = ['N', 'NE', 'E', 'SE', 'S', 'SW', 'W', 'NW']
    startIdx = arr.index(curr)
    deg = 0
    while arr[startIdx] != dest:
        startIdx += 1
        deg += 45
        if startIdx == len(arr):
            startIdx = 0
    if deg == 180:
        print('U-turn')
        return
    elif deg < 180:
        print(f'Turn {deg} degrees starboard')
    else:
        rem = 360 - deg
        print(f'Turn {rem} degrees port')

solve(curr, dest)