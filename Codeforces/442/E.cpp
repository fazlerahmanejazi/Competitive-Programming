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

const int N=400005 ;
int left (int p) {return p<<1 ;}
int right(int p) {return (p<<1)+1 ; }

int n, m, u, v, x, c, T, res, q ;
string t ;
vvi adj ;
vi light, start, finish, idx(4*N), tree(4*N, 0), lazy(4*N, 0) ;

void init()
  {
    light.resize(n+1) ; adj.resize(n+1) ;
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
    if(l==r) tree[p]=light[idx[l]] ;
    else
      {
        build(left(p), l, (l+r)/2) ;
        build(right(p), (l+r)/2+1, r) ;
        tree[p]=tree[left(p)]+tree[right(p)] ;
      }
  }

void lazyUpdate(int p, int s, int e)
  {
    tree[p]=(e-s+1)-tree[p] ;
    if(s!=e) lazy[left(p)]^=1, lazy[right(p)]^=1 ;
    lazy[p]=0 ;
  }

void update(int p, int s, int e, int l, int r)
  {
  	if(lazy[p]) lazyUpdate(p, s, e) ;
    if(e<l || s>r) return ;
    if(l<=s && e<=r)
      {
        tree[p]=(e-s+1)-tree[p] ; ;
        if(s!=e) lazy[left(p)]^=1, lazy[right(p)]^=1 ;
        return ;
      }
    update(left(p), s, (s+e)/2, l, r) ;
    update(right(p), (s+e)/2+1, e, l, r) ;
    tree[p]=tree[left(p)]+tree[right(p)] ;
  }

int query(int p, int s, int e, int l, int r)
  {
    if(lazy[p]) lazyUpdate(p, s, e) ;
    if(e<l || s>r) return 0 ;
    if(l<=s && e<=r) return tree[p] ;
    return query(left(p), s, (s+e)/2, l, r)+query(right(p), (s+e)/2+1, e, l, r) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    init() ;
    for(int i=2 ; i<=n ; i++)
      {
        cin>> x ;
        adj[i].pb(x) ;
        adj[x].pb(i) ;
      }
    for(int i=1 ; i<=n ; i++) cin>> light[i] ;
    dfs(1, -1) ;
    build(1, 1, T) ;
    cin>> m ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> t >> x ;
        if(t=="pow") update(1, 1, T , start[x], finish[x]) ;
        else cout<< query(1, 1, T, start[x], finish[x])/2 << endl ;
      }
  }
