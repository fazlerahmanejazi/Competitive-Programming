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

int n, m, u, v, k ;
vvi adj ;
vector<vpii> query ;
vector<map<int, int>> cnt, colorCnt ;
vlli c, p, ans, tree ;

void init()
  {
    c.resize(n+1) ; adj.resize(n+1) ; ans.resize(m+1) ;
    cnt.resize(n+1) ; p.resize(n+1) ; query.resize(n+1) ;
    colorCnt.resize(n+1) ;
    for(int i=0 ; i<=n ; i++) p[i]=i ;
  }

int find(int i)
  {
    if(i!=p[i]) p[i]=find(p[i]) ;
    return p[i] ;
  }

int same(int i, int j)
  {
    return find(i)==find(j) ;
  }

void unionset(int u, int v)
  {
    int x=find(u), y=find(v), val, count ;
    if(x==y) return ;
    if(cnt[x].size()<cnt[y].size()) swap(x, y) ;
    for(auto i:cnt[y])
      {
        tie(val, count)=i ;
        while(count--)
          {
            cnt[x][val]++ ;
            colorCnt[x][cnt[x][val]]++ ;
          }
      }
    p[y]=x ;
  }

void dfs(int u, int prev)
  {
    cnt[u][c[u]]++ ; colorCnt[u][cnt[u][c[u]]]++ ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs(v, u) ;
          unionset(u, v) ;
        }
    for(auto i:query[u]) ans[i.se]=colorCnt[find(u)][i.fi] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    init() ;
    for(int i=1 ; i<=n ; i++) cin>> c[i] ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    for(int i=1 ; i<=m ; i++)
      {
        cin>> v >> k ;
        query[v].pb(mp(k, i)) ;
      }
    dfs(1, -1) ;
    for(int i=1 ; i<=m ; i++) cout<< ans[i] << endl ;
  }
