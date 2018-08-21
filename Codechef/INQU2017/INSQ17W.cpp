#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

ofstream outfile;
ifstream infile;

#define mod 1000000007

lli fact[400005] ;

void init()
  {
    fact[0]=1 ;
    for (int i=1 ; i<=400000 ; i++)
      fact[i]=fact[i-1]*i%mod ;
  }

lli fast_exp(lli base, lli exp)
  {
    lli res=1;
    while(exp>0)
      {
        if(exp%2==1) res=(res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
      }
    return res%mod;
  }

lli divide(lli a, lli b)
  {
    a=a%mod ;
    b=b%mod ;
    return (a*(getInverse(b)%mod))%mod ;
  }

lli nCr(lli n, lli r)
  {
    if(r>n || r<0 || n<0) return 0 ;
    return divide(divide(fact[n],fact[r]), fact[n-r])%mod ;
  }

lli up = 0, down = 0, rightt = 0, leftt = 0;

int main()
{
  fastIO ;
	infile.open("input.txt");
	outfile.open("output.txt");
	init() ;
	string s;
	cin >> s;
	lli q, i, x1, x2, y1, y2, x, y;
	cin >> q;

	for(i = 0; i < s.length(); ++i){
		if(s[i] == 'L')
			++leftt;
		else if(s[i] == 'R')
			++rightt;
		else if(s[i] == 'U')
			++up;
		else if(s[i] == 'D')
			++down;
	}

	for(i = 1; i <= q; ++i){
		cin >> x1 >> y1 >> x2 >> y2;
		lli s1 = 1, s2 = 1;
		x = abs(x1-x2);
		y = abs(y1-y2);
		if(x1 <= x2){
			s1 = nCr(leftt+rightt, rightt-x);
		}
		else{
			s1 = nCr(leftt+rightt, leftt-x);
		}

		if(y1 <= y2){
			s2 = nCr(down+up, up-y);
		}
		else{
			s2 = nCr(down+up, down-y);
		}

		lli ans = (s1*s2)%mod;

		cout << ans << "\n";
	}
}
