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

int n, m, u, v ;
vi color, a, b ;
vvi adj(n+1) ;
bool possible=true ;

void bipartite_check(int u, int c)
  {
    color[u]=c ;
    for(auto v:adj[u])
      if(color[v]==-1) bipartite_check(v, 1-c) ;
      else if(color[u]==color[v]) possible=false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    adj.resize(n+1) ;
    color.assign(n+1, -1) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    for(int i=1 ; i<=n ; i++)
      if(color[i]==-1)
        bipartite_check(i, 1) ;
    if(possible)
      {
        for(int i=1 ; i<=n ; i++)
          if(color[i]) a.pb(i) ;
          else b.pb(i) ;
        cout<< a.size() << endl ;
        for(int i=0 ; i<a.size() ; i++)
          cout<< a[i] << " " ;
        cout<< endl<< b.size() << endl ;
        for(int i=0 ; i<b.size() ; i++)
          cout<< b[i] << " " ;
      }
    else cout<< -1 ;
  }
