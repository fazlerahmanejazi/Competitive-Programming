#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define finishl '\n'
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

const int N=1000000 ;
int left (int p) {return p<<1 ;}
int right(int p) {return (p<<1)+1 ; }

lli n, m, u, v, t, x, c, T, res, q ;
vvi adj ;
vlli color, start, finish, idx(4*N), tree(4*N, 0), lazy(4*N, 0) ;

void init()
  {
    color.resize(n+1) ; adj.resize(n+1) ;
    start.resize(n+1) ; finish.resize(n+1) ;
  }

void dfs(int u, int par)
  {
    start[u]=++T ;
    idx[T]=u ;
    for(auto v:adj[u]) if(v!=par) dfs(v, u) ;
    finish[u]=++T ;
    idx[T]=u ;
  }

void build(int p, int l, int r)
  {
    if(l==r) tree[p]=1LL<<color[idx[l]] ;
    else
      {
        build(left(p), l, (l+r)/2) ;
        build(right(p), (l+r)/2+1, r) ;
        tree[p]=tree[left(p)]|tree[right(p)] ;
      }
  }

void lazyUpdate(int p, int s, int e)
  {
    tree[p]=1LL<<lazy[p] ;
    if(s!=e) lazy[left(p)]=lazy[right(p)]=lazy[p] ;
    lazy[p]=0 ;
  }

void update(int p, int s, int e, int l, int r, lli c)
  {
    if(lazy[p]) lazyUpdate(p, s, e) ;
    if(e<l || s>r) return ;
    if(l<=s && e<=r)
      {
        tree[p]=1LL<<c ;
        if(s!=e) lazy[left(p)]=lazy[right(p)]=c ;
        return ;
      }
    update(left(p), s, (s+e)/2, l, r, c) ;
    update(right(p), (s+e)/2+1, e, l, r, c) ;
    tree[p]=tree[left(p)]|tree[right(p)] ;
  }

lli query(int p, int s, int e, int l, int r)
  {
    if(lazy[p]) lazyUpdate(p, s, e) ;
    if(e<l || s>r) return 0 ;
    if(l<=s && e<=r) return tree[p] ;
    return query(left(p), s, (s+e)/2, l, r)|query(right(p), (s+e)/2+1, e, l, r) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    init() ;
    for(int i=1 ; i<=n ; i++) cin>> color[i] ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs(1, -1) ;
    build(1, 1, T) ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> t ;
        if(t==1)
          {
            cin>> x >> c ;
            update(1, 1, T , start[x], finish[x], c) ;
          }
        else
          {
            cin>> x ;
            q=query(1, 1, T, start[x], finish[x]) ;
            res=0 ;
            for(int i=0 ; i<64 ; i++) if(q&(1LL<<i)) res++ ;
            cout<< res << endl ;
          }
      }
  }
