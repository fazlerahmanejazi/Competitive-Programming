N, S=map(int, input().split())
dp={}
dp[(0, 0)]=1
def solve(n, s) :
	if s<0 :
		return 0
	if (n, s) in dp :
		return dp[(n, s)]
	if n==0 and s!=0 :
		dp[(n, s)]=0
		return 0
	res=0
	for i in range(0, 10) :
		res+=solve(n-1, s-i)
	dp[(n, s)]=res
	return res
if S%2 :
	print(0)
else :
	S=S/2 ;
	ans=solve(N, S)
	ans=ans*ans
	print(ans)
