#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 163577857
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
    base=base%mod ;
    while(exp>0)
      {
        if(exp%2) res=(res*base)%mod ;
        base=(base*base)%mod ;
        exp/=2;
      }
    return res%mod ;
  }

lli n, x, ans, fac[100010], dp[100010] ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    fac[0]=fac[1]=1 ;
    for(int i=2 ; i<=100000 ; i++) fac[i]=(i*fac[i-1])%mod ;
    dp[1]=n%mod ;
    for(int i=2 ; i<=n ; i++) dp[i]=(dp[i-1]+((fac[n]*((fast_exp(fac[i], mod-2)*fast_exp(fac[n-i], mod-2))%mod))%mod))%mod ;
    cout<< 1 << " " ;
    for(int i=2 ; i<n ; i++) cout<< dp[n-i] << " " ;
    cout<< 1 << " " ;
  }
