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

const int N=100005 ;
const int blockSize=sqrt(N) ;

lli n, m, q, u, v, x, y, idx, LG=20, l1, r1, l2, r2, l, r, L, R, T, curr ;
vvi adj(N) ;
vlli start(N), finish(N), rev(N), val(N), ans(N), cnt(30*N) ;
vector<tuple<lli, lli, lli, lli>> queries ;

bool cmp(tuple<lli, lli, lli, lli> &A, tuple<lli, lli, lli, lli> &B)
  {
    lli l1, l2, r1, r2 ;
    tie(l1, r1, ignore, ignore)=A ;
    tie(l2, r2, ignore, ignore)=B ;
    if(l1/blockSize==l2/blockSize) return r1<r2 ;
    else return l1<l2 ;
  }

void dfs(int u, int prev)
  {
    start[u]=++T ;
    rev[T]=u ;
    for(auto v:adj[u]) if(v!=prev) dfs(v, u) ;
    finish[u]=T ;
  }

void add(lli x)
  {
    y=val[rev[x]] ;
    cnt[y]++ ;
    for(int i=0 ; i<=LG ; i++) curr+=cnt[(y^(1<<i))] ;
  }

void del(lli x)
  {
    y=val[rev[x]] ;
    cnt[y]-- ;
    for(int i=0 ; i<=LG ; i++) curr-=cnt[(y^(1<<i))] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++) cin>> val[i] ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs(1, -1) ;
    cin>> q ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> l >> r ;
        tie(l1, r1, l2, r2)=mt(start[l], finish[l], start[r], finish[r]) ;
        queries.pb(mt(l1, r2, i, +1)) ;
        queries.pb(mt(l1, l2-1, i, -1)) ;
        queries.pb(mt(r1+1, r2, i, -1)) ;
        queries.pb(mt(r1+1, l2-1, i, +1)) ;
      }
    sort(all(queries), cmp) ;
    tie(l, r, ignore, ignore)=queries[0] ;
    r-- ;
    for(auto i:queries)
      {
        tie(L, R, idx, x)=i ;
        while(l<L) del(l++) ;
        while(l>L) add(--l) ;
        while(r<R) add(++r) ;
        while(r>R) del(r--) ;
        ans[idx]+=(x*curr) ;
      }
    for(int i=1 ; i<=q ; i++) cout<< ans[i] << endl ;
  }
