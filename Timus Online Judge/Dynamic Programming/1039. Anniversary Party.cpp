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

int n, u, v, x, s, dp[6010][2], c[6010] ;
set<int> temp ;
vvi adj(6010) ;

void dfs(int u)
  {
    int a=0, b=0 ;
    dp[u][1]=c[u] ;
    dp[u][0]=0 ;
    for(auto v:adj[u])
      {
        dfs(v) ;
        a+=max(dp[v][0], dp[v][1]) ;
        for(auto w:adj[v]) b+=max(dp[w][0], dp[w][1]) ;
      }
    dp[u][1]+=b ;
    dp[u][0]+=a ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++) cin>> c[i], temp.insert(i) ;
    for(int i=1 ; i<n ; i++) cin>> v >> u, adj[u].pb(v), temp.erase(v) ;
    s=*temp.begin() ;
    dfs(s) ;
    cout<< max(dp[s][0], dp[s][1]) ;
  }
