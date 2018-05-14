#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

int n, m, q, u, v, x, y, dia, s, t ;
vi p, diameter ;
vb done ;
vvi adj ;

void init()
  {
    adj.resize(n+1) ;
    p.resize(n+1) ;
    done.assign(n+1, false) ;
    diameter.assign(n+1, 0) ;
    for(int i=0 ; i<=n ; i++)
      p[i]=i ;
  }

void dfs(int u, int prev, int far)
  {
    if (far>dia)
      {
        dia=far ;
        s=u ;
      }
    for (int i=0 ; i<adj[u].size() ; i++)
      if(adj[u][i]!=prev)
        dfs(adj[u][i], u, far+1) ;
  }

int find(int i)
  {
    if(i!=p[i]) p[i]=find(p[i]) ;
    return p[i] ;
  }
bool same(int i, int j)
  {
    return find(i)==find(j) ;
  }
void unionset(int i, int j)
  {
    int x=find(i) ; int y=find(j) ;
    if(x!=y) p[x]=y ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> q ;
    init() ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
        unionset(u, v) ;
      }
    for(int i=1 ; i<=n ; i++)
      if(!done[find(i)])
        {
          done[find(i)]=true ;
          dia=-inf ;
          dfs(i, -1, 0) ;
          dfs(s, -1, 0) ;
          diameter[find(i)]=dia ;
        }
    for(int i=0 ; i<q ; i++)
      {
        cin>> t ;
        if(t==1)
          {
            cin>> x ;
            cout<< diameter[find(x)] << endl ;
          }
        else
          {
            cin>> x >> y ;
            if(!same(x, y))
              {
                dia=ceil(diameter[find(x)]/2.0)+ceil(diameter[find(y)]/2.0)+1 ;
                dia=max({diameter[find(x)], diameter[find(y)], dia}) ;
                unionset(x, y) ;
                diameter[find(x)]=dia ;
              }
          }
      }
  }
