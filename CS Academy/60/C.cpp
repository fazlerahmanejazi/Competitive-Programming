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

int n, m, k, x, isCycle, s=-1, T ;
vi inDeg, visit, taken, topo, ans ;
vvi adj, d ;

void check(int u)
  {
    visit[u]++ ;
    for(auto v:adj[u])
      if(!visit[v]) check(v) ;
      else if(visit[v]==1) isCycle=true ;
    visit[u]++ ;
  }

void dfs(int u)
  {
    visit[u]++ ;
    for(auto v:adj[u]) if(!visit[v]) dfs(v) ;
    topo.pb(u) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k >> m ;
    d.resize(n) ;
    inDeg.assign(k, 0) ;
    ans.resize(k) ;
    adj.resize(k) ;
    visit.assign(k, 0) ;
    taken.assign(k, 0) ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        {
          cin>> x ;
          d[i].pb(x) ;
        }
    for(int i=0 ; i<n ; i++)
      {
        bool allSame=1 ;
        for(int j=0 ; j<m ; j++) if(d[i][j]!=d[i][0]) allSame=0 ;
        if(!allSame) taken[d[i][0]]=1 ;
      }
    for(int i=0 ; i<n-1 ; i++)
      {
        int idx=-1 ;
        for(int j=0 ; j<m ; j++)
          if(d[i][j]!=d[i+1][j])
            {
              idx=j ;
              break ;
            }
        if(idx==-1)
          {
            cout<< -1 ;
            return 0 ;
          }
        adj[d[i][idx]].pb(d[i+1][idx]) ;
        inDeg[d[i+1][idx]]++ ;
      }
    for(int i=0 ; i<k ; i++) if(!visit[i]) check(i) ;
    for(int i=0 ; i<k ; i++)
      if(!taken[i] && !inDeg[i])
        {
          s=i ;
          break ;
        }
    if(isCycle || s==-1)
      {
        cout<< -1 ;
        return 0 ;
      }
    visit.assign(k, 0) ;
    dfs(s) ;
    reverse(all(topo)) ;
    for(auto i:topo) ans[i]=T++ ;
    for(int i=0 ; i<k ; i++)
      if(!visit[i] && !inDeg[i])
        {
          topo.clear() ;
          dfs(i) ;
          reverse(all(topo)) ;
          for(auto i:topo) ans[i]=T++ ;
        }
    for(auto i:ans) cout<< i << " " ;
  }
