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

int n, m, u, v, w, x, idx, dp[100005], inDeg[100005], s, ans, mx=inf ;
vb visit ;
vi S, E ;
vector<vector<tuple<int, int, int>>> adj ;

void dfs(int u, int val, int idx, int len)
  {
    int v, w, d ;
    visit[u]=true ;
    ans=max(ans, len) ;
    for(auto i:adj[u])
      {
        tie(v, w, d)=i ;
        if(d>idx)
          {
            if(w>val) dfs(v, w, d, len+1) ;
            else dfs(v, w, d, 0) ;
          }
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    adj.resize(n+1) ;
    visit.assign(n+1, false) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> u >> v >> w ;
        if(mx>w) mx=w, x=u ;
        E.pb(u) ;
        if(u==v) continue ;
        adj[u].pb(mt(v, w, i)) ;
        inDeg[v]++ ;
      }
    for(int i=1 ; i<=n ; i++) if(!inDeg[i]) S.pb(i) ;
    for(auto i:S) dfs(i, 0, 0, 0) ;
    for(auto i:E) if(!visit[i]) dfs(i, 0, 0, 0) ;
    dfs(x, 0, 0, 0) ;
    cout<< ans ;
  }
