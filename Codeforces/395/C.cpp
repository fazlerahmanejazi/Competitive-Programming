#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
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

int n, u, v, x=-1, y ;
vvi adj ;
vi color ;
vb visit ;
bool possible ;

void dfs(int u, int prev, int c)
  {
    visit[u]=true ;
    if(color[u]!=c) possible=false ;
    for(int i=0 ; i<adj[u].size() ; i++)
      if(!visit[adj[u][i]] && adj[u][i]!=prev)
        dfs(adj[u][i], prev, c) ;
  }

bool check(int z)
  {
    possible=true ;
    visit.assign(n+1, false) ;
    for(int i=0 ; i<adj[z].size() ; i++)
      if(!visit[adj[z][i]])
        dfs(adj[z][i], z, color[adj[z][i]]) ;
    if(possible) cout<< "YES" << endl << z ;
    return possible ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ; color.resize(n+1) ;
    for(int i=0 ; i<n-1 ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    for(int i=1 ; i<=n ; i++)
      cin>> color[i] ;
    for(int i=1 ; i<=n ; i++)
      {
        for(int j=0 ; j<adj[i].size() ; j++)
          if(color[i]!=color[adj[i][j]])
            {
              x=i ;
              y=adj[i][j] ;
              break ;
            }
        if(x!=-1) break ;
      }
    if(x==-1) cout<< "YES" << endl << 1 ;
    else if(check(x) || check(y)) return 0 ;
    else cout<< "NO" ;
    possible=true ;
  }
