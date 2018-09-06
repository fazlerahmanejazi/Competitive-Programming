#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define For(i,n) for(int i=0;i<n;i++)
#define Fre(i,a,b) for(int i = a; i < b; i++)
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define number_of_digit(n) __builtin_ffs(n);
#define ll long long
#define T int			// T can be signed and unsigned of int ,long ,long long
inline void print(T n)
{
	if (n == 0)
	{
		putchar('0');
		putchar('\n');
	}
	else if (n == -1)
	{
		putchar('-');
		putchar('1');
		putchar('\n');
	}
	else
	{
		char buf[11];
		buf[10] = '\n';
		int i = 9;
		while (n)
		{
			buf[i--] = n % 10 + '0';
			n /= 10;
		}
		while (buf[i] != '\n')
			putchar(buf[++i]);
	}
}
int read()
{
       int cc = getc(stdin);
       for (;cc < '0' || cc > '9';)  cc = getc(stdin);
       int ret = 0;
       for (;cc >= '0' && cc <= '9';)
       {
          ret = ret * 10 + cc - '0';
          cc = getc(stdin);
       }
      return ret;
}
string read1()
{
       int cc = getc(stdin);
       for (;cc < '0' || cc > '9';)  cc = getc(stdin);
       string r="";
       for (;cc >= '0' && cc <= '9';)
       {
          r+=cc;
          cc = getc(stdin);
       }
      return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);

  	ll n;
  	cin>>n;
  	ll a[n];
  	for(ll i=0;i<n;i++)cin>>a[i];
  	if(n==1)
  	{
  		cout<<a[0]<<endl;
  		return 0;
	  }
	  ll sum=0;
	  bool is=false,is1=false;
	  ll minimum=10000000000;
	for(ll i=0;i<n;i++)
	{
		sum+=abs(a[i]);
		if(a[i]<=0)is=true;
		if(a[i]>=0)is1=true;
		minimum=min(minimum,abs(a[i]));
	}
	if(is==true && is1==true)
	{
		cout<<sum<<endl;
	}
	else
	{
		sum-=2*minimum;//<<endl;
		cout<<sum<<endl;
		return 0;
	}
	return 0;
}
