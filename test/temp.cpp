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

lli n, u, v, a[300000], vals[300000], curr, ans, tot ;
vvi adj(300000) ;

void dfs_pre(lli u, lli prev, lli dist)
  {
    curr+=dist*a[u] ;
    vals[u]=a[u] ;
    tot+=a[u] ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs_pre(v, u, dist+1) ;
          vals[u]+=vals[v] ;
        }
  }

void dfs(lli u, lli prev, lli curr)
  {
    ans=max(curr, ans) ;
    for(auto v:adj[u])
      if(v!=prev)
        dfs(v, u, curr-2*vals[v]+tot) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs_pre(1, -1, 0) ;
    dfs(1, -1, curr) ;
    cout<< ans ;
  }
