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

lli n, m, u, v, x, ans, cycle_end, cycle_start ;
vlli c ;
vvi adj ;
vi visit, parent ;
vb isCycle ;
vpii cycles ;

void init()
  {
    adj.resize(n+1) ;
    visit.assign(n+1, 0) ;
    isCycle.assign(n+1, false) ;
    c.resize(n+1) ;
  }

void dfs_cycle(int u)
  {
    visit[u]=1 ;
    for(auto v:adj[u])
      if(!visit[v])
        {
          parent[v]=u ;
          dfs_cycle(v) ;
        }
      else if(visit[v]==1)
        {
          cycle_end=u ;
          cycle_start=v ;
          cycles.pb(mp(cycle_start, cycle_end)) ;
        }
    visit[u]=2 ;
  }

void find_cycle()
  {
    visit.assign(n+1, 0) ;
    parent.assign(n+1, -1) ;
    for(int i=1 ; i<=n ; i++) if(!visit[i]) dfs_cycle(i) ;
    for(auto C:cycles)
      {
        tie(cycle_start, cycle_end)=C ;
        m=c[cycle_start] ;
        for(int v=cycle_end ; v!=cycle_start ; v=parent[v]) m=min(m, c[v]) ;
        ans+=m ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    init() ;
    for(int i=1 ; i<=n ; i++) cin>> c[i] ;
    for(int i=1 ; i<=n ; i++) cin>> x, adj[i].pb(x) ;
    find_cycle() ;
    cout<< ans ;
  }
