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

int n, u, v, q, k ;
lli w ;
vector<vector<pair<int, lli>>> adj ;
vlli dist ;

void dfs(int u, int prev, lli d)
  {
    dist[u]=d ;
    for(int i=0 ; i<adj[u].size() ; i++)
      {
        pair<int, lli> temp=adj[u][i] ;
        int v=temp.fi ;
        lli x=temp.se ;
        if(v!=prev)
          dfs(v, u, d+x) ;
      }

  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    dist.assign(n+1, 0) ;
    for(int i=0 ; i<n-1 ; i++)
      {
        cin>> u >> v >> w ;
        adj[u].pb(mp(v, w)) ;
        adj[v].pb(mp(u, w)) ;
      }
    cin>> q >> k ;
    dfs(k, -1, 0) ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> u >> v ;
        cout<< dist[u]+dist[v] << endl ;
      }
  }
