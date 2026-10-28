from curses.ascii import isalpha

f, key = input().split()
word = input()

def clean(word: str):
    res = ""
    for c in word:
        if isalpha(c):
            res += c
    return res.lower()

def encrypt(wd):
    word = clean(wd)
    # print(word)
    i = 0
    n = len(word)
    res = ['' for _ in range(len(word))]
    flag = 1

    for c in key:
        k = ord(c) - ord('a') + 2
        # print(k)
        move = k
        j = 0 if flag == 1 else n-1
        while j >= 0 and j < n and i < n and move <= n and move >= 0:
            if res[j] != '':
                j+= flag
                continue
            move -= 1
            if move == 0:
                res[j] = word[i]
                move = k
                i+=1
            j += flag
        # print(res)
        flag = -flag

    j = 0 if flag == 1 else n - 1
    # print(j)
    for idx in range(i, len(word)):
        while res[j] != '':
            j += flag

        res[j] = word[idx]
        i += 1
    return ''.join(res)


def decrypt(word):
    n = len(word)
    word = list(word)
    res = ""
    flag = 1

    for c in key:
        k = ord(c) - ord('a') + 2
        move = k
        j = 0 if flag == 1 else n - 1
        while j >= 0 and j < n and move <= n and move >= 0:
            if word[j] == '':
                j += flag
                continue
            move -= 1
            if move == 0:
                res += word[j]
                word[j] = ''
                move = k
            j += flag
        flag = -flag

    # print(res)
    # print(word)
    if flag == 1:
        for c in word:
            if c == '': continue
            res += c
    else:
        rev = reversed(word)
        for c in rev:
            if c == '': continue
            res += c
    return res

    return res

if f == 'E':
    m = encrypt(word)
    print(m)
else:
    m = decrypt(word)
    print(m)