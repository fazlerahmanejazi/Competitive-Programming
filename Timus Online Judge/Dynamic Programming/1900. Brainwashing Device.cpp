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
    int n, K, x, ans=0, dp[505][505], nxt[505][505], sum[505][505] ;
    vector<vpii> a(505) ;
    memset(sum, 0, sizeof sum) ;
    memset(dp, 0, sizeof dp) ;
    memset(nxt, 0, sizeof nxt) ;
    cin>> n >> K ;
    for(int i=1 ; i<n ; i++)
      for(int j=i+1 ; j<=n ; j++)
        {
          cin>> x ;
          a[j].pb(mp(i, x)) ;
        }
    for(int i=1 ; i<=n ; i++)
      {
        x=0 ;
        for(int j=i+1 ; j<=n ; j++)
          {
            for(auto l:a[j]) if(l.fi<=i) x+=l.se ;
            sum[i][j]=x ;
          }
      }
    for(int i=n-1 ; i>=1 ; i--)
      for(int j=1 ; j<=K ; j++)
        for(int k=i+1 ; k<=n ; k++)
          if(dp[i][j]<dp[k][j-1]+sum[i][k])
            {
              dp[i][j]=dp[k][j-1]+sum[i][k] ;
              nxt[i][j]=k ;
            }
    x=1 ;
    for(int i=1 ; i<=n ; i++) if(dp[i][K]>ans) ans=dp[i][K], x=i ;
    cout<< ans << endl ;
    if(ans) while(K--) cout<< x << " ", x=nxt[x][K+1] ;
    else while(K--) cout<< x << " ", x++ ; //when there are no passengers
  }
