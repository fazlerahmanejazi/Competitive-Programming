import sys
n, m = map(int, input().split())
l=m+1
r=n+1
ans=n
if n==1:
	ans=1
else:
	if m<n:
		while l<=r:
			i=(l+r)//2
			y=2*m +(i-m)*(i-m+1)
			x=2*n
			if y>=x :
				ans=i
				r=i-1
			else :
				l=i+1
	else:
		ans=n
print(int(ans))
