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

int n, u, v, x, res, dp[6005] ;
vvi adj ;
vi r, seq ;

void dfs(int u, int prev)
  {
    int idx, x, sz=seq.size() ;
    idx=lower_bound(seq.begin(), seq.end(), r[u])-seq.begin() ;
    if(idx==sz) seq.pb(r[u]) ;
    else x=seq[idx], seq[idx]=r[u] ;
    res=max(res, idx+1) ;
    for(auto v:adj[u]) if(v!=prev) dfs(v, u) ;
    if(idx==sz) seq.pop_back() ;
    else seq[idx]=x ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    r.resize(n+1) ;
    for(int i=1 ; i<=n ; i++) cin>> r[i] ;
    for(int i=1 ; i<=n-1 ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    for(int i=1 ; i<=n ; i++) dfs(i, -1) ;
    cout<< res ;
  }
