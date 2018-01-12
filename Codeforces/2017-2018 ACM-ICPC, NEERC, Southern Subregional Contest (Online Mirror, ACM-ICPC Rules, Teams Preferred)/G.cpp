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

int n, m, s, u, v, x, t, c, curr ;
vector<vector<pair<int, int>>> adj ;
vpii edge ;
vi orient ;
vb visit ;

void dfsD(int u)
  {
    visit[u]=true ;
    int v, c ;
    for(int i=0 ; i<adj[u].size() ; i++)
      {
        tie(v, c)=adj[u][i] ;
        if(visit[v]) continue ;
        if(!c) dfsD(v) ;
        else
          {
            if(edge[c-1].fi==u) orient[c-1]=-1 ;
            else orient[c-1]=1 ;
          }
      }
  }

void dfs(int u)
  {
    visit[u]=true ;
    int v, c ;
    for(int i=0 ; i<adj[u].size() ; i++)
      {
        tie(v, c)=adj[u][i] ;
        if(visit[v]) continue ;
        if(!c) dfs(v) ;
        else
          {
            if(edge[c-1].fi==u) orient[c-1]=1 ;
            else orient[c-1]=-1 ;
            dfs(v) ;
          }
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> s ;
    adj.resize(n+1) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> t >> u >> v ;
        if(t==1) adj[u].pb(mp(v, 0)) ;
        else c++, edge.pb(mp(u, v)), adj[u].pb(mp(v, c)), adj[v].pb(mp(u, c)) ; ;
      }
    visit.assign(n+1, false) ;
    orient.assign(c+1, 0) ;
    dfs(s) ;
    curr=0 ;
    for(int i=1 ; i<=n ; i++) if(visit[i]) curr++ ;
    cout<< curr << endl ;
    for(int i=0 ; i<c ; i++)
      if(orient[i]>=0) cout<< '+' ;
      else cout<< '-' ;
    cout<< endl ;
    visit.assign(n+1, false) ;
    orient.assign(c+1, 0) ;
    dfsD(s) ;
    curr=0 ;
    for(int i=1 ; i<=n ; i++) if(visit[i]) curr++ ;
    cout<< curr << endl ;
    for(int i=0 ; i<c ; i++)
      if(orient[i]>=0) cout<< '+' ;
      else cout<< '-' ;
  }
