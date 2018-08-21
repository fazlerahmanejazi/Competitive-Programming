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

lli n, D[100], ten[100], fac[100], ans, sum, cnt[10], extra ;

void init()
  {
    ten[0]=1 ;
    for(int i=1 ; i<=50 ; i++) ten[i]=(10*ten[i-1])%mod ;
    for(int i=1 ; i<=50 ; i++) ten[i]=(ten[i]+ten[i-1])%mod ;
    fac[1]=fac[0]=1 ;
    for(int i=1 ; i<=50 ; i++) fac[i]=(i*fac[i-1])%mod ;
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

lli getInverse(lli n)
  {
    return fast_exp(n, mod-2) ;
  }

lli divide(lli a, lli b)
  {
    a=a%mod ;
    b=b%mod ;
    return (a*(getInverse(b)%mod))%mod ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    init() ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> D[i] ;
        sum+=D[i] ;
        cnt[D[i]]++ ;
      }
    ans=(((sum*ten[n-1])%mod)*fac[n-1])%mod ;
    for(int i=0 ; i<=9 ; i++) ans=divide(ans, fac[cnt[i]]) ;
    if(cnt[0] && n>1)
      {
        extra=((((sum*ten[n-2])%mod)*fac[n-2])%mod)%mod ;
        cnt[0]-- ;
        for(int i=0 ; i<=9 ; i++) extra=divide(extra, fac[cnt[i]]) ;
      }
    ans=(ans-extra+mod)%mod ;
    cout<< ans ;
  }
