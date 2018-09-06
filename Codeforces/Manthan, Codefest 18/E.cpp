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

int n, m, k, u, v, x ;
vector<set<int>> adj ;
vi deg, ans ;
vpii edges ;
vb done ;
set<pii> s ;

void init()
  {
    deg.assign(n+1, 0) ; done.assign(n+1, false) ;
    adj.resize(n+1) ; ans.resize(m+1) ;
    edges.resize(m+1) ;
  }

void updateDeg(int v)
  {
    s.erase(mp(deg[v], v)) ;
    deg[v]-- ;
    s.insert(mp(deg[v], v)) ;
  }

void update()
  {
    while(!s.empty() && (*s.begin()).fi<k)
      {
        u=(*s.begin()).se ;
        done[u]=true ;
        for(auto v:adj[u])
          {
            updateDeg(v) ;
            adj[v].erase(u) ;
          }
        s.erase(mp(deg[u], u)) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> k ;
    init() ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> u >> v ;
        adj[u].insert(v) ;
        adj[v].insert(u) ;
        deg[u]++ ;
        deg[v]++ ;
        edges[i]=mp(u, v) ;
      }
    for(int i=1 ; i<=n ; i++) s.insert(mp(deg[i], i)) ;
    update() ;
    for(int i=m ; i>=1 ; i--)
      {
        ans[i]=s.size() ;
        tie(u, v)=edges[i] ;
        if(!done[u] && !done[v])
          {
            adj[u].erase(v) ;
            adj[v].erase(u) ;
            updateDeg(u) ;
            updateDeg(v) ;
          }
        update() ;
      }
    for(int i=1 ; i<=m ; i++) cout<< ans[i] << endl ;
  }
