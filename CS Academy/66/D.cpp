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

int n, grid[1005][1005], m, s ;
vvi adj(1005) ;
vpii ans ;
vi c, temp ;
vb avail(1005, true), taken ;

void dfs(int u)
  {
    taken[u]=true ;
    temp.pb(u) ;
    for(auto v:adj[u])
      if(avail[v])
        {
          if(!taken[v]) dfs(v) ;
          else if(v==u) c=temp, c.pb(u) ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=n ; j++)
        cin>> grid[i][j] ;
    for(int j=1 ; j<=n ; j++)
      for(int i=1 ; i<=n ; i++)
        if(grid[i][j])
          adj[j].pb(i) ;
    for(int i=1 ; i<=n ; i++)
      if(avail[i])
        {
          s=i ;
          taken.assign(n+1, false) ;
          temp.clear() ; c.clear() ;
          dfs(i) ;
          if(!c.empty())
            {

            }
        }
