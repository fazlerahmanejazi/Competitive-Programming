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

lli n, m, k, u, v, x, w, c, dist[20][20] ;
vlli imp ;
vb visit ;
vector<vpii> adj ;

lli prim()
  {
    lli ans=0 ;
    priority_queue<pair<lli, lli>> pq ;
    visit[1]=true ;
    for(auto v:adj[1]) if(!visit[v.fi]) pq.push(mp(-v.se, -v.fi)) ;
    while(!pq.empty())
      {
        auto x=pq.top() ;
        pq.pop() ;
        w=-x.fi ; u=-x.se ;
        if(!visit[u])
          {
            ans+=w ;
            visit[u]=true ;
            for(auto v:adj[u]) if(!visit[v.fi]) pq.push(mp(-v.se, -v.fi)) ;
          }
      }
    return ans ;
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        imp.clear() ; adj.clear() ;
        cin>> n >> m >> k ;
        adj.resize(k+1) ;
        visit.assign(k+1, false) ;
        imp.resize(k) ;
        memset(dist, inf, sizeof dist) ;
        for(int i=1 ; i<=m ; i++)
          {
            cin>> u >> v >> x ;
            dist[u][v]=dist[v][u]=x ;
          }
        for(int i=0 ; i<k ; i++) cin>> imp[i] ;
        for(int k=1 ; k<=n ; k++)
          for(int i=1 ; i<=n ; i++)
            for(int j=1 ; j<=n ; j++)
              dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]) ;
        for(int i=0 ; i<k ; i++)
          for(int j=0 ; j<k ; j++)
            if(imp[i]!=imp[j])
              {
                adj[i+1].pb(mp(j+1, min(dist[imp[i]][imp[j]], dist[imp[j]][imp[i]]))) ;
                adj[j+1].pb(mp(i+1, min(dist[imp[i]][imp[j]], dist[imp[j]][imp[i]]))) ;
              }
        cout<< prim() << endl ;
      }
  }
