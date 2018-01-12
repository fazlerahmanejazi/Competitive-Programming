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

int T, n, u, v, x, d=-1, l, r ;
vvi adj, dist ;
vb visit ;
vi ans ;
bool possible ;

void init()
  {
    adj.clear() ;
    adj.resize(n+1) ;
    dist.clear() ;
    dist.resize(n+1) ;
    visit.assign(n+1, false) ;
    ans.clear() ;
    possible=true ;
  }

void dfs(int u, int t)
  {
    visit[u]=true ;
    dist[t].pb(u) ;
    d=max(d, t) ;
    for(int i=0 ; i<adj[u].size() ; i++)
      if(!visit[adj[u][i]])
        dfs(adj[u][i], t+1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        init() ;
        for(int i=0 ; i<n-1 ; i++)
          {
            cin>> u >> v ;
            adj[u].pb(v) ;
            adj[v].pb(u) ;
          }
        dfs(1, 1) ;
        for(int j=d-1 ; j>=1 ; j-=2)
          for(int i=0 ; i<dist[j].size() ; i++)
            ans.pb(dist[j][i]) ;
        for(int j=d ; j>=1 ; j-=2)
          for(int i=0 ; i<dist[j].size() ; i++)
            ans.pb(dist[j][i]) ;
        for(int i=1 ; i<ans.size() ; i++)
          {
            u=ans[i] ; v=ans[i-1] ;
            for(int j=0 ; j<adj[u].size() ; j++)
              if(adj[u][j]==v)
                possible=false ;
          }
        if(possible)
          {
            for(int i=0 ; i<ans.size() ; i++)
              cout<< ans[i] << " " ;
            cout<< endl ;
          }
        else cout<< -1 << endl ;
      }
  }
