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

template<class T, int SZ> struct DSU
  {
    T p[SZ+1] ;
    DSU() { for(int i=0 ; i<=SZ ; i++) p[i]=i ; }
    T find(T i)
      {
        if(i!=p[i]) p[i]=find(p[i]) ;
        return p[i] ;
      }
    bool same(T i, T j) { return find(i)==find(j) ; }
    void unionset(T i, T j)
      {
        T x=find(i) ; T y=find(j) ;
        if(x!=y) p[x]=y ;
      }
  } ;

lli n, m, x, y, c, X, Y, g, t, v ;
vi a, sz, col ;
vvi adj ;
vb blocked ;
DSU<int, 200005> p, q ;

void init()
  {
    adj.resize(n+1) ; a.resize(n+1) ;
    sz.assign(n+1, 1) ; blocked.assign(n+1, false) ;
    col.assign(n+1, 0) ;
  }

void update()
  {
    cin>> x >> c ;
    a[x]=c ;
  }

void connect()
  {
    cin>> x >> y ;
    if(p.same(x, y) && col[q.find(x)]==col[q.find(y)]) blocked[p.find(x)]=true ;
    else if(!p.same(x, y) && (blocked[p.find(x)] || blocked[p.find(y)])) p.unionset(x, y), blocked[p.find(x)]=true ;
    else if(!p.same(x, y))
      {
        p.unionset(x, y) ;
        if(col[q.find(x)]==col[q.find(y)])
          {
            col[q.find(y)]=1-col[q.find(y)] ;
            if(!adj[y].empty()) col[q.find(adj[y][0])]=col[q.find(x)] ;
          }
        if(!adj[y].empty())
          {
            c=col[q.find(x)] ;
            q.unionset(adj[y][0], x) ;
            col[q.find(x)]=c ;
          }
        if(!adj[x].empty())
          {
            c=col[q.find(y)] ;
            q.unionset(adj[x][0], y) ;
            col[q.find(y)]=c ;
          }
        adj[x].pb(y) ; adj[y].pb(x) ;
      }
  }

void query()
  {
    cin>> x >> y >> v ;
    if(!p.same(x, y) || (p.same(x, y) && blocked[p.find(x)])) cout<< 0 << endl ;
    else
      {
        tie(X, Y)=mp(v*a[x], a[y]) ;
        g=__gcd(X, Y) ;
        tie(X, Y)=mp(X/g, Y/g) ;
        if(col[q.find(x)]!=col[q.find(y)]) X*=-1 ;
        cout<< X << "/" << Y << endl ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    init() ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> t ;
        if(t==1) update() ;
        else if(t==2) connect() ;
        else query() ;
      }
  }
