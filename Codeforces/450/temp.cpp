#include <iostream>
using namespace std;

#define MAXN 100005
int bit1[MAXN];
int bit2[MAXN];
int a[MAXN];
int n;

void update(int bit[],int index,int val)
{
	while(index <= n)
	{
		bit[index]+=val;
		index += index&(-index);
	}
}
int getsum(int bit[],int index)
{
	int s=0;
	while(index > 0)
	{
		s += bit[index];
		index -= index&(-index);
	}
	return s;
}


int main() {
	// your code goes here
	cin >> n;
	long long uk = 0LL;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		uk += 1LL*getsum(bit1,a[i]);
		update(bit1,a[i],1);
	}
	long long res = 0LL;
	int el = 100000;
	for(int i = 0; i < n; i++)
	{
		long long rr = uk;
		rr -= 1LL*(getsum(bit2,a[i])+( n-a[i]-getsum(bit2,n)+getsum(bit2,a[i]) ) );
		if(rr == res)
		{
			el = min(el,a[i]);
		}
		else if(rr > res)res=rr,el=a[i];
		update(bit2,a[i],1);
	}
if(el==100000) el=1 ;
	cout << el;
	return 0;
}
