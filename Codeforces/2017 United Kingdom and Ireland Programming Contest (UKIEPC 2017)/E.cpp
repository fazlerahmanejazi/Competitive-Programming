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

int n, m, x, idx, curr, cap, cost, req, dp[5005][5005] ;
vi ans ;
vpii s ;
vector<tuple<int, int, int>> p ;

void reconstruct(int x, int y)
  {
    if(!x || !y) return ;
    tie(cap, cost, idx)=p[y] ;
    if(cap>=s[x].fi && dp[x][y]==dp[x-1][y-1]+cost)
      {
        ans[s[x].se]=idx ;
        reconstruct(x-1, y-1) ;
      }
    else reconstruct(x, y-1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    s.resize(n+1) ; p.resize(m+1) ; ans.resize(n+1) ;
    for(int i=1 ; i<=n ; i++) cin>> s[i].fi, s[i].se=i ;
    for(int i=1 ; i<=m ; i++) cin>> get<0>(p[i]) ;
    for(int i=1 ; i<=m ; i++) cin>> get<1>(p[i]) ;
    for(int i=1 ; i<=m ; i++) get<2>(p[i])=i ;
    sort(s.begin()+1, s.end()) ;
    sort(p.begin()+1, p.end()) ;
    memset(dp, inf, sizeof dp) ;
    for(int i=0 ; i<=m ; i++) dp[0][i]=0 ;
    for(int i=1 ; i<=m ; i++)
      if(get<0>(p[i])>=s[1].fi)
        dp[1][i]=min(dp[1][i-1], get<1>(p[i])) ;
    for(int i=2 ; i<=n ; i++)
      for(int j=i ; j<=m ; j++)
        {
          dp[i][j]=min(dp[i][j-1], dp[i][j]) ;
          tie(cap, cost, idx)=p[j] ;
          if(s[i].fi<=cap) dp[i][j]=min(dp[i][j], cost+dp[i-1][j-1]) ;
        }
    reconstruct(n, m) ;
    if(dp[n][m]==inf) cout<< "impossible" ;
    else for(int i=1 ; i<=n ; i++) cout<< ans[i] << " " ;
  }
