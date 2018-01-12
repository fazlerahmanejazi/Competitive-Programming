#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
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

class DSU
  {
    private: vi rank, p ;
    public:
      DSU(int n)
        {
          rank.assign(n, 0) ;
          p.assign(n, 0) ;
          for(int i=0 ; i<n ; i++) p[i]=i ;
        }
      int find(int i)
        {
          if(i!=p[i])
            p[i]=find(p[i]) ;
          return p[i] ;
        }
      bool same(int i, int j) {return find(i)==find(j) ;}
      void unionset(int i, int j)
        {
          int x=find(i) ; int y=find(j) ;
          if(!same(i,j))
            {
              if(rank[x]>rank[y]) p[y]=x ;
              else
                {
                  p[x]=y ;
                  if(rank[x]==rank[y]) rank[y]++ ;
                }
            }
        }
  } ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T, n, m, u, v, c ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> m ;
        vi deg(n+1, 0), ans(n+1, 0), avail(n+1, false) ;
        vvi nodes(n+1), adj(n+1) ;
        DSU dsu(n+1) ;
        for(int i=0 ; i<m ; i++)
          {
            cin>> u >> v ;
            adj[u].pb(v) ;
            adj[v].pb(u) ;
            deg[u]++ ; deg[v]++ ;
          }
        c=n ;
        for(int i=1 ; i<=n ; i++)
          nodes[deg[i]].pb(i) ;
        for(int i=n-1 ; i>=0 ; i--)
          {
            ans[i]=c-1 ;
            for(int j=0 ; j<nodes[i].size() ; j++)
              avail[nodes[i][j]]=true ;
            for(int j=0 ; j<nodes[i].size() ; j++)
              {
                u=nodes[i][j] ;
                for(int k=0 ; k<adj[u].size() ; k++)
                  {
                    v=adj[u][k] ;
                    if(avail[v] && !dsu.same(u, v))
                      {
                        dsu.unionset(u, v) ;
                        c-- ;
                      }
                  }
              }
          }
        for(int i=0 ; i<n ; i++)
          cout<< ans[i] << " " ;
        cout<< endl ;
      }
  }
