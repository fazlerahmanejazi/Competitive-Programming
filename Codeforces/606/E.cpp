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

int n, m, a, b, u, v, x, y ;
vvi adj ;
vb visit ;

void init()
  {
    adj.clear() ;
    adj.resize(n+1) ;
    x=y=0 ;
  }

int dfs(int u)
  {
    visit[u]=true ;
    for(auto v:adj[u]) if(!visit[v]) dfs(v) ;
  }

lli solve(int start, int skip)
  {
    lli cnt=0 ;
    visit.assign(n+1, false) ;
    visit[skip]=true ;
    dfs(start) ;
    for(int i=1 ; i<=n ; i++) if(!visit[i]) cnt++ ;
    return cnt ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int t ;
    cin>> t ;
    while(t--)
      {
        cin>> n >> m >> a >> b ;
        init() ;
        for(int i=1 ; i<=m ; i++)
          {
            cin>> u >> v ;
            adj[u].pb(v) ;
            adj[v].pb(u) ;
          }
        cout<< solve(a, b)*solve(b, a) << endl ;
      }
  }
