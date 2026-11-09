import sys


n = int(sys.stdin.readline().rstrip())
G = {
    'golf' : 'bob',
    "fishing" : "alice",
    "hockey" : "charlie"
}
def solve():
    for i in range(n):
        s = sys.stdin.readline().rstrip()
        s = s.split()
        name, game = s[0], s[-1]

        if G[game] == name:
            print(f"{name} already has {game}")
        else:
            print(f"{name} borrows {game} from {G[game]}")
            G[game] = name

solve()