x, y = input().split()
x, y = int(x), int(y)
grid = [input() for _ in range(x)]

valid = 0

def check(i, j):
    if i-1 < 0 or j-1 < 0 or i+1 >= x or j+1 >= y:
        return False

    return (
        grid[i-1][j-1] == 'O' and
        grid[i-1][j] == 'O' and
        grid[i-1][j+1] == 'O' and
        grid[i][j-1] == 'O' and
        grid[i][j+1] == 'O' and
        grid[i+1][j] == 'O' and
        grid[i+1][j-1] == 'O' and
        grid[i+1][j+1] == 'O'
    )

x_loc, y_loc = -1, -1
for i in range(x):
    for j in range(y):
        if grid[i][j] == '0' and check(i, j):
            valid += 1
            x_loc, y_loc = i, j

if valid == 0:
    print("Oh no!")
elif valid == 1:
    print(x_loc+1, y_loc+1)
else:
    print(f"Oh no! {valid} locations")



# 3 6
# OO0OOO
# 00OO0O
# 0O0OOO