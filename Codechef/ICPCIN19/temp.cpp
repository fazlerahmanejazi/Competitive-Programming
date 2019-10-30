#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 998244353
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

lli n, k, r, c, dp[2000][10] ;

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

lli solve(lli k, lli t)
  {
    if(dp[k][t]!=-1) return dp[k][t] ;
    lli ans=0 ;
    if(t==1)
      {
        lli x1=solve(k-1, 1) ;
        lli x2=solve(k-1, 2) ;
        lli y1=divide(n*n-n+1, n*n) ;
        lli y2=divide(1, 2*n*n) ;
        dp[k][t]=((x1*y1)%mod+(x2*y2)%mod)%mod ;
      }
    else if(t==2)
      {
        lli x1=solve(k-1, 1) ;
        lli x2=solve(k-1, 2) ;
        lli x3=solve(k-1, 3) ;
        lli y1=divide(n-1, n*n) ;
        lli y2=divide(2*n-1, 2*n) ;
        lli y3=divide(1, n*n) ;
        dp[k][t]=((x1*y1)%mod+(x2*y2)%mod+(x3*y2)%mod)%mod ;
      }
    else
      {
        lli x2=solve(k-1, 2) ;
        lli x3=solve(k-1, 3) ;
        lli y2=divide(n-1, 2*n*n) ;
        lli y3=divide(n*n-1, n*n) ;
        dp[k][t]=((x3*y3)%mod+(x2*y2)%mod)%mod ;
      }
    return dp[k][t] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int t ;
    cin>> t ;
    while(t--)
      {
        memset(dp, -1, sizeof dp) ;
        dp[0][1]=1 ;
        dp[0][2]=dp[0][3]=0 ;
        cin>> n >> k >> r >> c ;
        cout<< solve(k, 1) << endl ;
      }
  }
