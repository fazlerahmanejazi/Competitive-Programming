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

bitset<1010> mask[1010] ;
vector<vector<int>> adj ;
vector<bool> visit ;

void dfs(int v)
  {
    int to ;
    visit[v]=true ;
    for(int i=0 ; i<adj[v].size() ; i++)
      {
        to=adj[v][i] ;
        if(!visit[to]) dfs(to) ;
        mask[v] |= mask[to];
        mask[v].set(to);
      }
   }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T, n, x, y, ans, d, x1, x2, y1, y2, u, v ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        vpii points ;
        vector<tuple<int, int, int>> dist ;
        adj.clear() ; adj.resize(n) ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> x >> y ;
            points.pb(mp(x, y)) ;
            mask[i].reset() ;
          }
        for(int i=0 ; i<n ; i++)
          for(int j=i+1 ; j<n ; j++)
            {
              tie(x1, y1)=points[i] ;
              tie(x2, y2)=points[j] ;
              d=abs(x2-x1)+abs(y2-y1) ;
              dist.pb(mt(d, i, j)) ;
            }
        sort(all(dist)) ;
        for(int i=0 ; i<dist.size() ; i++)
          {
            tie(d, u, v)=dist[i] ;
            if(mask[u][v] || mask[v][u]) continue ;
            else
              {
                adj[u].pb(v) ;
                adj[v].pb(u) ;
                visit.assign(n, false) ;
                for(int i=0 ; i<n ; i++)
                  if(!visit[i])
                    dfs(i) ;
                ans=d ;
              }
          }
        cout<< ans ;
      }
  }
