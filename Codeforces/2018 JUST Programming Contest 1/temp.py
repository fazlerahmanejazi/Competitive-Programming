t=int(raw_input())

for _ in range(t):
	n, a=map(int, raw_input().split())
    l, r, ans=0, n-1, n-1
	tot, lo, hi = 2 * n * (a - 1), 1, n - 1
    while l<=r:
        m=(l+r)//2
        if((m*(m-1))//2+(n-m)
	while lo < hi:
		mid = (lo + hi + 1) // 2
		if mid * (mid + 1) <= tot:
			lo = mid
		else:
			hi = mid - 1
	print lo + 1
