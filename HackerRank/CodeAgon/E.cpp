#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

int n, m, u, v, c, x ;
lli ans, nodes, edges ;
vvi adj ;
vi degree ;
vb visit ;
vpii data ;

void dfs(int u)
  {
    visit[u]=true ;
    nodes++ ;
    edges+=degree[u] ;
    for(auto v:adj[u])
      if(!visit[v])
        dfs(v) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    adj.resize(n+1) ;
    visit.assign(n+1, false) ;
    degree.assign(n+1, 0) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
        degree[u]++ ;
        degree[v]++ ;
      }
    c=2 ;
    for(int i=1 ; i<=n ; i++)
      {
        nodes=edges=0 ;
        if(!visit[i])
          {
            dfs(i) ;
            ans+=(nodes*(nodes-1)) ;
            edges/=2 ;
            x=edges-nodes+1 ;
            c-=x ;
            data.pb(mp(nodes, edges)) ;
          }
      }
    sort(all(data)) ;
    if(c<=0) cout<< ans ;
    else if(c==1)
      {
        for(int i=0 ; i<data.size() ; i++)
          if(data[i].fi>1)
            {
              ans-=2*(data[i].fi-1) ;
              break ;
            }
        cout<< ans ;
      }
    else if(c==2)
      {
        for(int i=0 ; i<data.size() ; i++)
          if(data[i].fi>1)
            {
              ans-=2*(data[i].fi-1) ;
              data[i].fi-- ;
              data.pb(mp(1, 0)) ;
              break ;
            }
        sort(all(data)) ;
        for(int i=0 ; i<data.size() ; i++)
          if(data[i].fi>1)
            {
              ans-=2*(data[i].fi-1) ;
              break ;
            }
        cout<< ans ;
      }
  }
