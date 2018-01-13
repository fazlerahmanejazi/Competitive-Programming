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

bool pos=true ;
int n, m, u, v, x, cnt1, cnt2, res ;
vvi adj, radj, scc ;
vi in, out, T, temp ;
vb visit ;

void init()
  {
    adj.resize(n+1) ;
    radj.resize(n+1) ;
    visit.assign(n+1, false) ;
    in.assign(n+1, 0) ;
    out.assign(n+1, 0) ;
  }

void dfs_topo(int u)
  {
    visit[u]=true ;
    for(auto v:adj[u]) if(!visit[v]) dfs_topo(v) ;
    T.pb(u) ;
  }

void dfs(int u)
  {
    visit[u]=true ;
    for(auto v:radj[u]) if(!visit[v]) dfs(v) ;
    temp.pb(u) ;
  }

void f1(int u)
  {
    visit[u]=true ;
    for(auto v:adj[u]) if(!visit[v]) f1(v) ;
    cnt1++ ;
  }

void f2(int u)
  {
    visit[u]=true ;
    for(auto v:radj[u]) if(!visit[v]) f2(v) ;
    cnt2++ ;
  }

void kosaraju()
  {
    reverse(all(T)) ;
    visit.assign(n+1, false) ;
    for(auto u:T)
      if(!visit[u])
        {
          temp.clear() ;
          dfs(u) ;
          scc.pb(temp) ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    init() ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        radj[v].pb(u) ;
        out[u]++ ;
        in[v]++ ;
      }
    for(int i=1 ; i<=n ; i++) if(!visit[i]) dfs_topo(i) ;
    kosaraju() ;
    for(auto i:scc) if(i.size()>1) x++ ;
    if(x>1) pos=false ;
    for(auto s:scc)
      {
        visit.assign(n+1, true) ;
        for(auto u:s) visit[u]=false ;
        cnt1=cnt2=0 ;
        f1(s[0]) ;
        for(auto u:s) visit[u]=false ;
        f2(s[0]) ;
        if(cnt1!=cnt2) res++ ;
      }
    if(res>1) pos=false ;
    if(pos) cout<< "YES ";
    else cout<< "NO" ;
  }
