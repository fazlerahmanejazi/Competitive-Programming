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

lli fact[400005] ;

void init()
  {
    fact[0]=1 ;
    for(int i=1 ; i<=400000 ; i++) fact[i]=fact[i-1]*i%mod ;
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

lli nCr(lli n, lli r)
  {
    if(r>n || r<0) return 0 ;
    return divide(divide(fact[n],fact[r]), fact[n-r])%mod ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    init() ;
    lli n, m, k, T[200010], a, d, idx, P=0, Q=0 ;
    cin>> n >> m >> k ;
    memset(T, 0, sizeof T) ;
    vector<pii> data ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> a >> d ;
        idx=a ;
        while(idx<=n) T[idx]++, idx+=d ;
      }
    Q=nCr(m, k) ;
    for(int i=1 ; i<=n ; i++)
      if(T[i]>k) P=(P+Q)%mod ;
      else P=(P+Q-nCr(m-T[i], k-T[i])+mod)%mod ;
    cout<< divide(P, Q) ;
  }
