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

lli n, m, u, d, v, w, s, t, x, D, ans ;
vector<tuple<lli, lli, lli>> edges ;
vlli dpS, dpT, distS, distT ;
vector<pair<lli, lli>> temp ;
vector<vector<pair<lli, lli>>> adj ;
priority_queue<pair<lli, lli>, vector<pair<lli, lli>>, greater<pair<lli, lli>>> pq ;

void init()
  {
    adj.resize(n+1) ;
    dpS.assign(n+1, 0) ; dpT.assign(n+1, 0) ;
    distS.assign(n+1, INF) ; distT.assign(n+1, INF) ;
  }

void dijkstra(int start, vlli &dist, vlli &dp)
  {
    dist[start]=0 ;
    dp[start]=1 ;
    pq.push(mp(0LL, start)) ;
    while(!pq.empty())
      {
        tie(d, u)=pq.top() ; pq.pop() ;
        if(d>dist[u]) continue ;
        for(auto v:adj[u])
          if(dist[u]+v.se<dist[v.fi])
            {
              dist[v.fi]=dist[u]+v.se ;
              pq.push(mp(dist[v.fi], v.fi)) ;
              dp[v.fi]=dp[u] ;
            }
          else if(dist[u]+v.se==dist[v.fi]) dp[v.fi]=(dp[v.fi]+dp[u])%mod ;
      }
  }

void calc()
  {
    D=distS[t] ;
    assert(distS[t]==distT[s]) ;
    ans=(dpS[t]*dpS[t])%mod ;
    for(int i=1 ; i<=n ; i++)
      if(distS[i]==D/2 && distT[i]==D/2)
        {
          x=(dpS[i]*dpT[i])%mod ;
          ans=(ans-(x*x)%mod+mod)%mod ;
        }
    for(auto i:edges)
      {
        tie(u, v, w)=i ;
        if(distS[u]<D/2 && distT[v]<D/2 && distS[u]+distT[v]+w==D)
          {
            x=(dpS[u]*dpT[v])%mod ;
            ans=(ans-(x*x)%mod+mod)%mod ;
          }
        if(distS[v]<D/2 && distT[u]<D/2 && distS[v]+distT[u]+w==D)
          {
            x=(dpS[v]*dpT[u])%mod ;
            ans=(ans-(x*x)%mod+mod)%mod ;
          }
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> s >> t ;
    init() ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> u >> v >> w ;
        adj[u].pb(mp(v, w)) ;
        adj[v].pb(mp(u, w)) ;
        edges.pb(mt(u, v, w)) ;
      }
    dijkstra(s, distS, dpS) ;
    dijkstra(t, distT, dpT) ;
    calc() ;
    cout<< ans ;
  }
