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

const int N=200000+100 ;
const int L=20 ;

template<class T, int SZ> struct BIT
  {
    T bit[SZ+1] ;
    BIT() { memset(bit, 0, sizeof bit) ; }
    void update(int k, T val)  { for( ; k<=SZ ; k+=(k&-k)) bit[k]+=val ; }
    T getSum(int k)
      {
        T temp=0 ;
        for ( ; k>0 ; k-=(k&-k)) temp+=bit[k] ;
        return temp ;
      }
    T query(int l, int r) { return getSum(r)-getSum(l-1) ; }
  } ;

int n, q, u, v, r, x, w, t, idx, timer, tin[N], tout[N], D[N], up[N][30] ;
vector<vpii> adj(N) ;
vector<tuple<int, int, int>> edges ;
BIT<int, N> tree ;

void dfs(int u, int p=1, int d=0)
  {
    tin[u]=++timer ;
    D[u]=d ;
    up[u][0]=p ;
    for(int i=1 ; i<=L ; i++) up[u][i]=up[up[u][i-1]][i-1] ;
    for(auto v:adj[u]) if(v.fi!=p) dfs(v.fi, u, d+v.se) ;
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

int dist(int u, int v)
  {
    int l=lca(u, v) ;
    int d=(D[u]+tree.getSum(tout[u]))+(D[v]+tree.getSum(tout[v]))-2*(D[l]+tree.getSum(tout[l])) ;
    return d ;
  }

void update()
  {
    idx-- ;
    tie(u, v, w)=edges[idx] ;
    if(D[v]<D[u]) swap(u, v) ;
    tree.update(tin[v], x-w) ;
    tree.update(tout[v]+1, -x+w) ;
    get<2>(edges[idx])=x ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v >> w ;
        adj[u].pb(mp(v, w)) ;
        adj[v].pb(mp(u, w)) ;
        edges.pb(mt(u, v, w)) ;
      }
    dfs(1) ;
    cin>> q ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> t ;
        if(t==1) cin>> idx >> x, update() ;
        else cin>> u >> v, cout<< dist(u, v) << endl ;
      }
  }
