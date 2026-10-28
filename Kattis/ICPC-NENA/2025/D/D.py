n = int(input())
arr = input().split()
arr = [int(i) for i in arr]
sm = sum(arr)
arr.sort()
top = arr[-1]
# print(top, sm//2)
def rec(curr):
    curr.sort()
    m = len(curr)
    # print(curr)


    if not curr: return 1e9
    # print(curr)
    if curr[-1] > (sm // 2):
        # print(curr[-1], top, "HERE")
        return 0
    if m == 1 and curr[0] < top:
        return 1e9
    mn = int(1e9)

    j = 0
    votes = curr[j]
    while j < m-1 and curr[j] == curr[j+1]:
        j +=1
        votes += curr[j]
    if j >= m: return 1e9

    for i in range(j+1, m):
        nxt = curr[::]
        nxt[i] += votes
        if i < m-1 and nxt[i] > arr[-1]: continue

        x = rec(nxt[j+1:])
        if x == 1e9: continue
        mn = min(x + 1, mn)
    
    return mn


arr2 = arr[:n-1]
res = rec(arr2)
if res == 1e9 or res == -1:
    print("IMPOSSIBLE TO WIN")
else:
    print(res)