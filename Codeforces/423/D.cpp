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

int n, k, remain, u, v, far, s, dia ; ;
vvi adj ;

void dfs(int u, int prev, int far)
  {
    if (far>dia)
      {
        dia=far ;
        s=u ;
      }
    for (int i=0 ; i<adj[u].size() ; i++)
      if(adj[u][i]!=prev)
        dfs(adj[u][i], u, far+1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    remain=n-k ;
    dia=-inf ;
    vi corners(k+1) ;
    vpii edges ;
    adj.resize(n+1) ;
    for(int i=1 ; i<=k ; i++)
      corners[i]=k+1 ;
    remain-- ;
    for(int i=1 ; i<=k ; i++)
      if(remain>0 && k+1+i<=n)
        {
          edges.pb(mp(k+1, k+1+i)) ;
          adj[k+1].pb(k+1+i) ;
          adj[k+1+i].pb(k+1) ;
          corners[i]=k+1+i ;
          remain-- ;
        }
    while(remain>0)
      {
        for(int i=1 ; i<=k ; i++)
          {
            int x=corners[i] ;
            if(x+k<=n && remain>0)
              {
                edges.pb(mp(x, x+k)) ;
                adj[x].pb(x+k) ;
                adj[x+k].pb(x) ;
                corners[i]=x+k ;
                remain-- ;
              }
          }
      }
    for(int i=1 ; i<=k ; i++)
      {
        int x=corners[k-i+1] ;
        edges.pb(mp(x, i)) ;
        adj[x].pb(i) ;
        adj[i].pb(x) ;
      }
    dfs(1, -1, 0) ;
    dfs(s, -1, 0) ;
    cout<< dia << endl ;
    for(int i=0 ; i<edges.size() ; i++)
      {
        cout<< edges[i].fi << " " << edges[i].se << endl ;
      }

  }
