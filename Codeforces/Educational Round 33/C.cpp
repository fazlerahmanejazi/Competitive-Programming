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

lli n, m, u, v, x, curr, ans ;
vvi adj(100005) ;
vb visit(100005, 0) ;
vlli c(100005) ;

void dfs(int u)
  {
    visit[u]=true ;
    curr=min(curr, c[u]) ;
    for(auto v:adj[u])
      if(!visit[v])
        dfs(v) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=1 ; i<=n ; i++) cin>> c[i] ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    for(int i=1 ; i<=n ; i++)
      if(!visit[i])
        {
          curr=inf ;
          dfs(i) ;
          ans+=curr ;
        }
    cout<< ans ;
  }
