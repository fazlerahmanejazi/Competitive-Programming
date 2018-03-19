#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int n, m, x, y ;
vector<vector<pair<int, int>>> adj ;
vb visit ;
vvi data ;
vi unlock, color ;
bool possible ;

void dfs(int t, int p)
  {
    color[t]=p ;
    for(int i=0 ; i<adj[t].size() ; i++)
      {
        int v=adj[t][i].fi ; int c=adj[t][i].se ;
        if(color[v]==-1)
          {
            if(c==1) dfs(v, p) ;
            else dfs(v, 1-p) ;
          }
        else
          {
            if(c==1 && color[v]!=color[t]) possible=false ;
            else if(c==0 && color[v]==color[t]) possible=false ;
          }
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    unlock.resize(n+1) ;
    color.assign(m+1, -1) ;
    data.resize(n+1) ;
    adj.resize(m+1) ;
    possible=true ;
    for(int i=1 ; i<=n ; i++)
      cin>> unlock[i] ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> x ;
        for(int j=1 ; j<=x ; j++)
          {
            cin>> y ;
            data[y].pb(i) ;
          }
      }
    for(int i=1 ; i<=n ; i++)
      {
        x=data[i][0] ; y=data[i][1] ;
        adj[x].pb(mp(y, unlock[i])) ;
        adj[y].pb(mp(x, unlock[i])) ;
      }
    for(int i=1 ; i<=m ; i++)
      if(color[i]==-1)
        dfs(i, 0) ;
    if(possible) cout<< "YES" ;
    else cout<< "NO" ;
  }
