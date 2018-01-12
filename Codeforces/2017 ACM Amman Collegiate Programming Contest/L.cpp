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

lli n, m, u, v, c, ans ;
vector<vpii> adj ;
vlli dist ;

bool bellmanFord()
  {
    dist.assign(n+1, 0) ;
    for(int i=0 ; i<n-1 ; i++)
      for(int u=1 ; u<=n ; u++)
        for(auto v:adj[u])
          dist[v.fi]=min(dist[v.fi], dist[u]+v.se) ;
    for(int u=1 ; u<=n ; u++)
      for(auto v:adj[u])
        if(dist[v.fi]>dist[u]+v.se)
          return true ;
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> m ;
        adj.clear() ; adj.resize(n+1) ;
        ans=inf ;
        for(int i=0 ; i<m ; i++)
          {
            cin>> u >> v >> c ;
            adj[u].pb(mp(v, c)) ;
            ans=min(ans, c) ;
          }
        if(ans>=0) cout<< ans << endl ;
        else if(bellmanFord()) cout<< "-inf" << endl ;
        else
          {
            for(int i=1 ; i<=n ; i++)
              ans=min(dist[i], ans) ;
            cout<< ans << endl ;
          }
      }
  }
