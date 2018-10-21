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

class maxBipartiteMatching
  {
    vvi &G ;
    public:
    vi match, mark ;
    int max_match, stamp, n ;
    maxBipartiteMatching(vvi &bipartite_graph, int sz): G(bipartite_graph)
      {
        match.assign(sz+1, -1) ;
        mark.assign(sz+1, -1) ;
        n=sz ;
        stamp=0 ;
      }

    bool augmentPath(int u)
      {
        for(auto v:G[u])
          {
            if(mark[v]==stamp) continue ;
            mark[v]=stamp ;
            if(match[v]==-1 || augmentPath(match[v]))
              {
                match[v]=u ;
                return true ;
              }
          }
        return false ;
      }

    int maxMatching()
      {
        max_match=0 ;
        for(int i=1 ; i<=n ; i++)
          {
            stamp++ ;
            if(augmentPath(i)) max_match++ ;
          }
        return max_match ;
      }
  } ;

int T, n, grid[505][505], check[505][505] ;
char c ;
vvi adj ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        memset(check, 0, sizeof check) ;
        adj.clear() ;
        adj.resize(n+1) ;
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=n ; j++)
            {
              cin>> c ;
              if(c=='.') grid[i][j]=0 ;
              else grid[i][j]=1 ;
            }
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=n ; j++)
            if(grid[i][j]) break ;
            else check[i][j]++ ;
        for(int j=1 ; j<=n ; j++)
          for(int i=n ; i>=1 ; i--)
            if(grid[i][j]) break ;
            else check[i][j]++ ;
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=n ; j++)
            if(check[i][j]==2)
              adj[i].pb(j) ;
        maxBipartiteMatching M(adj, n) ;
        cout<< M.maxMatching() << endl ;
      }
  }
