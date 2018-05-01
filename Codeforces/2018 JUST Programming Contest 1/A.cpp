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

lli fact[410005], power[410005] ;

void init()
  {
    fact[0]=power[0]=1 ;
    for(int i=1 ; i<=410000 ; i++) fact[i]=(fact[i-1]*i)%mod ;
    for(int i=1 ; i<=410000 ; i++) power[i]=(power[i-1]*2)%mod ;
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
    return divide(divide(fact[n], fact[r]), fact[n-r])%mod ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    init() ;
    int T ;
    cin>> T ;
    while(T--)
      {
        lli n, m, r, x, ans, P, Q ;
        cin>> n >> m ;
        n=abs(n) ;
        if(m<n) cout<< 0 << endl ;
        else
          {
            if(n%2!=m%2) cout<< 0 << endl ;
            else
              {
                P=nCr(m, (n+m)/2) ;
                Q=power[m] ;
                cout<< divide(P, Q) << endl ;
              }
          }
      }
  }
