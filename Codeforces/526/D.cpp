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

lli n, u, v, w, x, ans, f[400000], dp[400000] ;
vector<vpii> adj(400000) ;

void dfs(int u, int prev)
  {
    dp[u]=f[u] ;
    vlli temp ;
    for(auto v:adj[u])
      if(v.fi!=prev)
        {
          dfs(v.fi, u) ;
          temp.pb(-v.se+dp[v.fi]) ;
          dp[u]=max(dp[u], -v.se+dp[v.fi]+f[u]) ;
        }
    sort(all(temp)) ;
    if(temp.size()>1) ans=max(ans, temp[temp.size()-1]+temp[temp.size()-2]+f[u]) ;
    ans=max(dp[u], ans) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++) cin>> f[i] ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v >> w ;
        adj[u].pb(mp(v, w)) ;
        adj[v].pb(mp(u, w)) ;
      }
    dfs(1, -1) ;
    cout<< ans ;
  }
