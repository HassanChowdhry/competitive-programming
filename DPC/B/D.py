"""
if can turn left and empy square: turn left and move forward
elif can move forward do so
else turn 90 ddegress



"""
def main():
    cases = int(input())
    for i in range(cases):
        mazeSize = input().split()
        mazeX = int(mazeSize[0])
        mazeY = int(mazeSize[1])

        start = input().split()
        startX = int(start[0])-1
        startY = int(start[1])-1

        finish = input().split()
        finishX = int(finish[0])-1
        finishY = int(finish[1])-1

        mazeArray = []
        for a in range(mazeX):
            row = input().split()
            tmp = []
            for c in row:
                tmp.append(c)
            mazeArray.append(tmp)

      
        curX = startX
        curY = startY

        rotation = 0
        rotationChange = 0

        success = False
        while True:
            if rotationChange >= 4:
                break

            nextLeft = getNextLeft(rotation)
            coordXL = nextLeft[0] + curX
            coordYL = nextLeft[1] + curY

            nextForward = getNextForward(rotation)
            coordXF = nextForward[0] + curX
            coordYF = nextForward[1] + curY

            
            
            if (coordYL < mazeY-1 and coordXF < mazeX-1) and mazeArray[coordYL][coordXL] == "0":
                curX = coordXL
                curY = coordYL
                rotation = (rotation +1)%4
                rotationChange = 0
            elif((coordXF < mazeX-1 and coordYF < mazeY-1) and mazeArray[coordYF][coordXF] == "0"):
                curX = coordXF
                curY = coordYF
                rotationChange = 0

            else:
                rotation = (rotation - 1) % 4
                rotationChange += 1
            if curX == finishX and curY == finishY:
                success = True
                break
    print("1" if success else "0")

                
            
            

        




def getNextLeft(rotation):
    if rotation == 0: # left
        return (0,-1)
    elif rotation == 1: # down
        return (1,0)
    elif rotation == 2: # right
        return (0,1)
    elif rotation == 3: #up 
        return(-1,0)
def getNextForward(rotation):
    if rotation == 0: # left
        return (-1, 0)
    elif rotation == 1: # down
        return (0,1)
    elif rotation == 2: #right:
        return (1,0)
    elif rotation == 3: # up
        return (0,-1)
    
    
main()

# (0,1) right
# (-1, 0) # up
# (0, -1) # left
# (1,0) # down