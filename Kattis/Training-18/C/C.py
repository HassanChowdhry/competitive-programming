from collections import defaultdict
import sys
from pprint import pprint

M = int(sys.stdin.readline())
costs = [0] + list(map(int, sys.stdin.readline().split()))
N,E = list(map(int, sys.stdin.readline().split()))
members = defaultdict(set)
MAX_S = 0
for i in range(E):
    tj, pj = list(map(int, sys.stdin.readline().split()))
    MAX_S = max(MAX_S, tj)
    members[pj].add(tj)

# print(M)
# print(costs)
# print(N,E)
# print(members)

def solve():
    currPlate = defaultdict(lambda: -1)
    costPerMember = defaultdict(int)
    nextP = 2
    currPlate[0] = 1
    plate0 = 2
    for t in range(1, MAX_S+1):

        for i in range(N, 0, -1):
            currPlate[i] = currPlate[i-1]
        
        currPlate[0] = plate0

        for i in range(1, N + 1):
            if t in members[i]:
                plateIdx = currPlate[i]
                if plateIdx != -1:
                    costPerMember[i] += costs[plateIdx]
                    currPlate[i] = -1

        if (currPlate[N] == -1 ):
            nextP += 1
            nextP %= M
            if (nextP == 0): nextP = M
            plate0 = nextP
        else:
            plate0 = currPlate[N]
    

    ans = [0] * (N + 1) 
    for k, v in costPerMember.items():
        ans[k] = v
    
    for x in ans[1:]:
        print(x)
    # pprint(dict(costPerMember))

solve()