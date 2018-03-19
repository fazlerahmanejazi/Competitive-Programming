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

map<lli, lli> dp ;

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

lli solve(lli x, lli y)
  {
    if(y%x) return 0 ;
    if(x==y) return 1 ;
    lli t=y/x, curr ;
    if(dp[t]) return dp[t] ;
    curr=(fast_exp(2, t-1)-solve(t, t)+mod)%mod ;
    for(lli i=2 ; i<=sqrt(t) ; i++)
      if(!(t%i))
        {
          curr=(curr-solve(i, t)+mod)%mod ;
          if(t/i!=i) curr=(curr-solve(t/i, t)+mod)%mod ;
        }
    dp[t]=curr ;
    return curr ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli x, y ;
    cin>> x >> y ;
    cout<< solve(x, y) << endl ;
  }
