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

const int N=200005 ;

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

int n, m, u, v, x, val, T ;
vi idx(4*N), depth(N), a(N), start(N), finish(N) ;
vvi adj(N) ;
BIT<int, N> tree[2] ;

void dfs(int u, int par, int d)
  {
    start[u]=++T ;
    depth[u]=d ;
    idx[T]=u ;
    for(auto v:adj[u]) if(v!=par) dfs(v, u, d+1) ;
    finish[u]=++T ;
    idx[T]=u ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs(1, 0, 0) ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> x ;
        if(x==1)
          {
            cin>> val ;

          }
        else
          {


          }
      }
  }
