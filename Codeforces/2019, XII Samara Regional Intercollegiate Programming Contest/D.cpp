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

const int N=500000+100 ;
const int L=20 ;

int n, q, u, v, r, b, x, lcaR, lcaB, timer, tin[N], tout[N], depth[N], up[N][30] ;
bool check1, check2 ;
vvi adj(N) ;
vi red, blue ;

void dfs(int u, int p=1, int d=0)
  {
    tin[u]=++timer ;
    depth[u]=d ;
    up[u][0]=p ;
    for(int i=1 ; i<=L ; i++) up[u][i]=up[up[u][i-1]][i-1] ;
    for(auto v:adj[u]) if(v!=p) dfs(v, u, d+1) ;
    tout[u]=++timer ;
  }

bool is_ancestor(int u, int v)
  {
    return tin[u]<=tin[v] && tout[u]>=tout[v] ;
  }

int lca(int u, int v)
  {
    if(u==v) return u ;
    if(is_ancestor(u, v)) return u ;
    if(is_ancestor(v, u)) return v ;
    for(int i=L ; i>=0 ; i--)
      if(!is_ancestor(up[u][i], v))
        u=up[u][i] ;
    return up[u][0] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs(1, 1, 0) ;
    cin>> q ;
    for(int i=1 ; i<=q ; i++)
      {
        red.clear() ; blue.clear() ;
        cin>> r >> b ;
        for(int j=0 ; j<r ; j++) cin>> x, red.pb(x) ;
        for(int j=0 ; j<b ; j++) cin>> x, blue.pb(x) ;
        lcaR=red[0] ; lcaB=blue[0] ;
        for(int j=0 ; j<r ; j++) lcaR=lca(lcaR, red[j]) ;
        for(int j=0 ; j<b ; j++) lcaB=lca(lcaB, blue[j]) ;
        if(lcaR!=lcaB)
          {
            check1=check2=true ;
            for(int j=0 ; j<r ; j++) if(is_ancestor(lcaB, red[j])) check1=false ;
            for(int j=0 ; j<b ; j++) if(is_ancestor(lcaR, blue[j])) check2=false ;
            if(check1 || check2) cout<< "YES" << endl ;
            else cout<< "NO" << endl ;
          }
        else cout<< "NO" << endl ;
      }
  }
