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

const int N=200010 ;

lli n, k, u, v ;
vvi adj(N) ;
vi sz(N, 0) ;
vector<char> _rank(N) ;
vb del(N, false) ;

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

void decompose(int u, char r)
  {
    dfs_sz(u, u) ;
    int c=find_centroid(u, u, sz[u]/2) ;
    del[c]=true ;
    _rank[c]=r ;
    for(auto v:adj[c]) if(!del[v]) decompose(v, r+1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    decompose(1, 'A') ;
    for(int i=1 ; i<=n ; i++) cout<< _rank[i] << " " ;
  }
