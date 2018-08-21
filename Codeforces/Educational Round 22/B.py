x, y, l, r = map(int, input().split())
a=1
b=1
arr=[]
ans=0
while a<=r*x:
    b=1
    while b<=r*y:
        arr.append(a+b)
        b=b*y
    a=a*x
arr.append(l-1)
arr.append(r+1)
arr.sort()
for z in range(1, len(arr)) :
    if arr[z]<=r+1 :
      if arr[z-1]>=l-1:
        if arr[z]-arr[z-1]-1>ans :
            ans=arr[z]-arr[z-1]-1
print(ans)
