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

#define MOD 998244353

lli fast_exp(lli base, lli exp)
  {
    lli res=1 ;
    while(exp>0)
      {
        if(exp%2) res=(res*base)%MOD ;
        base=(base*base)%MOD ;
        exp/=2;
      }
    return res%MOD ;
  }

lli get(lli n)
  {
    if(n==1) return 1 ;
    return ((n+1)*fast_exp(2, n-2))%MOD ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, idx=1, ans=0 ;
    cin>> n ;
    vlli a(n+1) ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=n ; i>=1 ; i--) ans=(ans+(a[i]*get(idx++))%MOD)%MOD ;
    cout<< ans ;
  }
