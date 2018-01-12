#include <bits/stdc++.h>
using namespace std ;

#define inf LLONG_MAX
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using plli = pair<long long int, int> ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vll = vector<long long int> ;

int T, n, k, x, m, s, a, b ;
long long int w, old ;
vector<vector<pii > > adj ;
plli temp ;
vll dist ;
vi common ;

void dijkstra(int start, long long int d)
  {
    int u, v ;
    priority_queue<plli , vector<plli> , greater<plli> > discovered ;
    discovered.push(mp(d, start)) ;
    dist[start]=d ;
    if(start<=k && dist[start]<old) old=dist[start] ;
    while(!discovered.empty())
      {
        temp=discovered.top() ;
        discovered.pop() ;
        w=temp.ff ; u=temp.ss ;
        if(dist[u]<w) continue ;
        for(int i=0 ; i<adj[u].size() ; i++)
          {
            temp=adj[u][i] ;
            w=temp.ss ; v=temp.ff ;
            if(dist[u]+w < dist[v])
              {
                dist[v]=dist[u]+w  ;
                discovered.push(mp(dist[v], v)) ;
                if(v<=k && dist[v]<old) old=dist[v] ;
              }
          }
      }
  }

int main()
 {
  ios_base::sync_with_stdio (false) ; cin.tie(0) ;
  int T ;
  cin>> T ;
  while(T--)
    {
      cin>> n >> k >> x >> m >> s ;
      adj.clear() ;
      common.clear() ;
      dist.assign(n+1, inf) ;
      adj.resize(n+1) ;
      old=inf ;
      for(int i=0 ; i<m ; i++)
        {
          cin>> a >> b >> w ;
          if(a<=k) common.pb(a) ;
          if(b<=k) common.pb(b) ;
          adj[a].pb(mp(b, w)) ;
          adj[b].pb(mp(a, w)) ;
        }
      if(s<=k)
        for(int i=0 ; i<common.size() ; i++)
          {
            adj[common[i]].pb(mp(s, x)) ;
            adj[s].pb(mp(common[i], x)) ;
          }
      dijkstra(s, 0) ;
      for(int i=1 ; i<=k ; i++)
        if(dist[i]>x+old)
          {
            dist[i]=x+old ;
            dijkstra(i, dist[i]) ;
          }
      for(int i=1 ; i<=n ; i++)
        cout<< dist[i] << " " ;
      cout<< endl ;
    }
  }
