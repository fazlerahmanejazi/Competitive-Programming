def check (list,a,b,c):
    if list[a+c][b] == '*' and list[a-c][b] == '*' and list[a][b+c] == '*' and list[a][b-c] == '*':
        return 1
    else:
        return 0
n,m = map(int, raw_input().split())
list = []
for a in range (n):
    s = raw_input()
    s = s.strip()
    list.append(s)
bl = [[['-'] for i in range (m)] for c in range (n)]
for a in range (n):
    for b in range (m):
        if list[a][b] == '*':
            bl[a][b] = 0
first = []
last = []
size = []
for a in range (1,n-1):
    for b in range (1,m-1):
        if list[a][b] == '*':
            if check(list,a,b,1) == 1:
                bl[a][b] = 1
                bl[a+1][b] = 1
                bl[a-1][b] = 1
                bl[a][b-1] = 1
                bl[a][b+1] = 1
                try:
                    if check (list,a,b,2) == 0:
                        first.append(a+1)
                        last.append(b+1)
                        size.append(1)
                except:
                    first.append(a+1)
                    last.append(b+1)
                    size.append(1)
                for c in range (2, n):
                    try:
                        if check (list,a,b,c) == 0:
                            temp = c
                            if temp != 2:
                                first.append(a+1)
                                last.append(b+1)
                                size.append(temp-1)
                                break
                            elif temp == 2:
                                break
                        elif check (list,a,b,c) == 1:
                            bl[a+c][b] = 1
                            bl[a-c][b] = 1
                            bl[a][b-c] = 1
                            bl[a][b+c] = 1
                    except:
                        break
ans  = len(first)
for a in range (0,n):
    for b in range (m):
        if bl[a][b] == 0:
            ans = -1
            break
print ans
if ans != -1:
    for a in range (0, len(first)):
        print first[a],last[a],size[a]
