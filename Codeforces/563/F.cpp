#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
//#define endl '\n'
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

const int N=200010 ;

lli n, k, u, v, depx ;
vvi adj(N) ;
vi sz(N, 0), par(N), dep(N, 0) ;
vb del(N, false) ;

int query(int u, char c)
  {
    int x ;
    cout<< c << " " << u << endl ;
    cin>> x ;
    return x ;
  }

void dfs(int u, int prev, int d)
    {
      par[u]=prev ;
      dep[u]=d ;
      for(auto v:adj[u]) if(!del[v] && v!=prev) dfs(v, u, d+1) ;
    }

void dfs_sz(int u, int prev)
  {
    sz[u]=1 ;
    for(auto v:adj[u])
      if(!del[v] && v!=prev)
        {
          dfs_sz(v, u) ;
          sz[u]+=sz[v] ;
        }
  }

int find_centroid(int u, int prev, int r)
  {
    for(auto v:adj[u])
      if(!del[v] && v!=prev && sz[v]>r)
        return find_centroid(v, u, r) ;
    return u ;
  }

void decompose(int u)
  {
    dfs_sz(u, u) ;
    int c=find_centroid(u, u, sz[u]/2) ;
    del[c]=true ;
    int d=query(c, 'd') ;
    if(!d)
      {
        cout<< "! " << c << endl ;
        return ;
      }
    else if(d+dep[c]==depx) decompose(query(c, 's')) ;
    else decompose(par[c]) ;
  }

int main()
  {
    //ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    depx=query(1, 'd') ;
    dfs(1, 1, 0) ;
    decompose(1) ;
  }
