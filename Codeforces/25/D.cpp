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

int n, u, v, x, idx=1 ;
vvi adj ;
vi a;
set<pii> edges ;
vb visit ;

void dfs(int u, int prev)
  {
    visit[u]=true ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          if(!visit[v]) dfs(v, u) ;
          else edges.insert(mp(min(u, v), max(u, v))) ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    visit.assign(n+1, false) ;
    for(int i=1 ; i<n ; i++) cin>> u >> v, adj[u].pb(v), adj[v].pb(u) ;
    for(int i=1 ; i<=n ; i++) if(!visit[i]) a.pb(i), dfs(i, -1) ;
    cout<< a.size()-1 << endl ;
    for(auto i:edges) cout<< i.fi << " " << i.se << " " << a[idx] << " " << a[idx-1] << endl, idx++ ;
  }
