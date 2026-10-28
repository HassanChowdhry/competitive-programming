from typing import Set
n, t = input().split()
n, t = int(n), int(t)

arr = [input() for _ in range(t)]
pre = []
ss = []
for team in arr:
    freq = set()
    valid = True
    for c in team:
        if c in freq:
            valid = False
            break
        freq.add(c)

        if ord(c) - ord('A') >= n:
            valid = False
            break

    if valid:
        pre.append(team)
        ss.append(set(team))

t = len(pre)
# print(ss)
res = [0]
def valid(i, sub, curr):
    return len(curr.intersection(ss[i])) == 0

def dfs(i, sub, curr: Set[int]):
    res[0] = max(res[0], len(sub))
    if i >= t:
        return

    dfs(i+1, sub, curr)

    if valid(i, sub, curr):
        sub.append(arr[i])
        dfs(i+1, sub, curr.union(ss[i]))
        sub.pop()

dfs(0, [], set())
print(res[0])


