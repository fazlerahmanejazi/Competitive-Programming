#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

lli fast_exp(lli base, lli exp)
  {
    lli res=1 ;
    while(exp>0)
      {
        if(exp%2) res=(res*base)%mod ;
        base=(base*base)%mod ;
        exp/=2;
      }
    return res%mod ;
  }

lli getInverse(lli n)
  {
    return fast_exp(n, mod-2) ;
  }

lli divide(lli a, lli b)
  {
    a=a%mod ; b=b%mod ;
    return (a*(getInverse(b)%mod))%mod ;
  }

lli get(lli x1, lli y1, lli x2, lli y2)
  {
    lli a=abs(x2-x1), b=abs(y2-y1) ;
    if(!a) return b+1 ;
    else if(!b) return a+1 ;
    else return __gcd(a, b)+1 ;
  }

lli nCr(lli n)
  {
    if(n<3) return 0 ;
    lli res=n%mod ;
    res=(res*(n-1))%mod ;
    res=(res*(n-2))%mod ;
    res=divide(res, 6) ;
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        lli x[4], y[4], l[3], ans, tot=0 ;
        for(int i=0 ; i<3 ; i++) cin>> x[i] >> y[i] ;
        x[3]=x[0] ; y[3]=y[0] ;
        for(int i=0 ; i<3 ; i++) l[i]=get(x[i], y[i], x[i+1], y[i+1]), tot+=l[i] ;
        tot-=3 ;
        ans=nCr(tot%mod) ;
        for(int i=0 ; i<3 ; i++) ans=(ans-nCr(l[i]%mod)+mod)%mod ;
        cout<< ans << endl ;
      }
  }
