from math import floor

def getClockScore(clock):
  hours = int(clock[0:2])
  minutes = int(clock[3:5])
  ratio = (1.0 / 180.0)
  
  if ((hours == 3 and minutes > 0) or (hours > 3 and hours < 9)):
    return 0.0

  if (hours == 12 and minutes == 0):
      return 1.0
  if ((hours == 3 or hours == 9) and minutes == 0):
      return 0.0
  
  if (hours < 12 and hours >= 9):
      hours -= 9; 
  else:
    if (hours == 12): hours = 0
    hours = 2 - hours
    minutes = 60 - minutes
    minutes = minutes % 60

  minutes += (hours * 60)

  return ratio * float(minutes)

tests = int(input())
maxscore = 0
maxname = ""

for _ in range(tests):
  thing = input().split()
  name, h, w, clock = thing
  h = float(h)
  w = float(w)
  
  # print(h, w)
  cs = getClockScore(clock)
  score = floor(((5.0 * h) + w) * cs)
  
  if (maxscore == score and name != maxname):
    maxname = "tie"
  if (maxscore < score):  
    maxscore = score
    maxname = name
  
print(f'{maxname} {maxscore}')
