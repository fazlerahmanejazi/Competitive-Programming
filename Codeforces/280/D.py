n, x, y = map(int, input().split(' '))
x, y = y, x

def check(m, r):
    a = m//x
    b = m//y
    if a+b >= r:
        return True
    else:
        return False

for i in range(n) :
    s = int(input())
    l = 0
    r = 1000000000000000000
    ans = r
    while l<=r:
        m=(l+r)//2
        if check(m, s):
            r = m-1
            ans = min(ans, m)
        else:
            l = m+1
    if ans%x == 0 and ans%y == 0:
        print("Both")
    elif ans%x == 0:
        print("Vanya")
    else:
        print("Vova")
