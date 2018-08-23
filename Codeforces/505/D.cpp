#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3 f3f3f
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
    int n, u, v, l, r ;
    bool dp[705][705][2], edge[705][705], ans=false ;
    cin>> n ;
    vi a(n+1) ;
    memset(dp, false, sizeof dp) ;
    memset(edge, false, sizeof edge) ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=1 ; i<=n ; i++) dp[i][i][0]=dp[i][i][1]=true ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=n ; j++)
        if(__gcd(a[i], a[j])>1)
          edge[i][j]=1 ;
    for(int len=2 ; len<=n ; len++)
      for(int i=1 ; i<=n ; i++)
        {
          l=i ; r=i+len-1 ;
          for(int j=l ; j<=r ; j++)
            {
              dp[l][r][0]|=(dp[l+1][j][1]&&dp[j][r][0]&&edge[l][j]) ;
              dp[l][r][1]|=(dp[l][j][1]&&dp[j][r-1][0]&&edge[r][j]) ;
            }
        }
    for(int i=1 ; i<=n ; i++) ans|=(dp[1][i][1]&&dp[i][n][0]) ;
    if(ans) cout<< "Yes" ;
    else cout<< "No" ;
  }
