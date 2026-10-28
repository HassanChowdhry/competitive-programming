line = input().split()

w = int(line[0])
s = int(line[1])

t = 29260
g = 29370


c = s * (s + 1) / 2

total_t = c * t

rem = w - total_t

print(int(rem//110))

