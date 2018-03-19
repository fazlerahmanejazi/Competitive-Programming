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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n ;
    cin>> n ;
    vi val(n+1) ;
    pii dp[n+1][2] ;
    for(int i=0 ; i<=n ; i++)
      dp[i][0]=dp[i][1]=mp(0, 0) ;
    for(int i=1 ; i<=n ; i++)
      cin>> val[i] ;
    dp[n][0].fi=val[n] ; dp[n][0].se=0 ;
    dp[n][1].fi=0 ; dp[n][1].se=val[n] ;
    for(int i=n-1 ; i>=1 ; i--)
      {
        if(val[i]+dp[i+1][1].fi>dp[i+1][0].fi)
          {
            dp[i][0].fi=val[i]+dp[i+1][1].fi ;
            dp[i][0].se=dp[i+1][1].se ;
          }
        else
          {
            dp[i][0].fi=dp[i+1][0].fi ;
            dp[i][0].se=val[i]+dp[i+1][0].se ;
          }
        if(val[i]+dp[i+1][0].se>dp[i+1][1].se)
          {
            dp[i][1].se=val[i]+dp[i+1][0].se ;
            dp[i][1].fi=dp[i+1][0].fi ;
          }
        else
          {
            dp[i][1].se=dp[i+1][1].se ;
            dp[i][1].fi=val[i]+dp[i+1][1].fi ;
          }
      }
    cout<< dp[1][0].se << " " << dp[1][0].fi ;
  }
