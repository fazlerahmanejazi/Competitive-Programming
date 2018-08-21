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

int n, u, v, x, centroid ;
vi sz ;
vvi adj ;

void dfs(int u, int prev)
  {
    sz[u]++ ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs(v, u) ;
          sz[u]+=sz[v] ;
        }
  }

void getCentroid(int u, int prev)
  {
    int mx=-1, big=-1 ;
    bool check=true ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          if(sz[v]>n/2) check=false ;
          if(sz[v]>mx) mx=sz[v], big=v ;
        }
    if(check) centroid=u ;
    if(big!=-1)
      {
        sz[u]-=sz[big] ;
        sz[big]+=sz[u] ;
        getCentroid(big, u) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    sz.assign(n+1, 0) ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs(1, 0) ;
    getCentroid(1, 0) ;
    cout<< centroid ;
  }
