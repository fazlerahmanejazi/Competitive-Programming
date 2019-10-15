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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m, u, v, x, c=1, e=0 ;
    cin>> n >> m ;
    vi check(n+1, 0) ;
    vector<set<int>> adj(n+1) ;
    vvi parts(4) ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> u >> v ;
        adj[u].insert(v) ;
        adj[v].insert(u) ;
      }
    for(int i=1 ; i<=3 ; i++)
      {
        x=-1 ;
        for(int j=1 ; j<=n ; j++)
          if(!check[j])
            {
              x=j ;
              check[j]=i ;
              break ;
            }
        if(x==-1) return cout<< -1, 0 ;
        for(int j=1 ; j<=n ; j++) if(!check[j] && adj[x].find(j)==adj[x].end()) check[j]=i ;
      }
    for(int i=1 ; i<=n ; i++)
      if(!check[i]) return cout<< -1, 0 ;
      else parts[check[i]].pb(i) ;
    for(int i=1 ; i<=3 ; i++)
      for(int j=i+1 ; j<=3 ; j++)
        for(auto u:parts[i])
          for(auto v:parts[j])
            if(adj[u].find(v)==adj[u].end()) return cout<< -1, 0 ;
            else e++ ;
    if(e!=m) return cout<< -1, 0 ;
    for(int i=1 ; i<=n ; i++) cout<< check[i] << " " ;
  }
