#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

lli n, c, u, x1, x2, ans ;
lli dp[110][110] ;

lli solve(lli day, lli upg, lli curr)
  {
    if(day>n || curr<0) return 0 ;
    if(day==n)
      {
        dp[day][upg]=curr+x1+upg*x2 ;
        return dp[day][upg] ;
      }
    if(curr<dp[day][upg]) return dp[day][upg] ;
    lli y1=0, y2=0, now ;
    now=curr+x1+upg*x2 ;
    if(now>=u) y1=solve(day+1, upg+1, now-u) ;
    y2=solve(day+1, upg, now) ;
    y1=max(y1, y2) ;
    dp[day][upg]=max(y1, dp[day][upg]) ;
    return dp[day][upg] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> c >> x1 >> u >> x2 ;
    memset(dp, 0, sizeof dp) ;
    ans=max(solve(1, 0, c), solve(1, 1, c-u)) ;
    cout<< ans ;
  }
