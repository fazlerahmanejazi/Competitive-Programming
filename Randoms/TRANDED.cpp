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

lli T, n, u, v, x, ans ;
vlli dp, score ;
vvi adj ;

void init()
  {
    dp.clear() ; score.clear() ; adj.clear() ;
    dp.resize(n+1) ; score.resize(n+1) ; adj.resize(n+1) ;
    ans=-INF ;
  }

void dfs(int u, int prev)
  {
    dp[u]=score[u] ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs(v, u) ;
          dp[u]+=max(dp[v], 0LL) ;
        }
    ans=max(ans, dp[u]) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        init() ;
        for(int i=1 ; i<=n ; i++) cin>> score[i] ;
        for(int i=1 ; i<n ; i++)
          {
            cin>> u >> v ;
            adj[u].pb(v) ;
            adj[v].pb(u) ;
          }
        dfs(1, -1) ;
        cout<< ans << endl ;
      }
  }
