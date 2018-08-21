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

int n, m, u, v, s, x ;
bool isCycle, taken[200005][2] ;
vvi adj ;
vi temp, ans, visit ;

void dfs(int u, int p)
  {
    taken[u][p]=true ;
    temp.pb(u) ;
    for(auto v:adj[u]) if(!taken[v][1-p]) dfs(v, 1-p) ;
    if(adj[u].empty() && p) ans=temp ;
    temp.pop_back() ;
  }

void check(int u)
  {
    visit[u]++ ;
    for(auto v:adj[u])
      if(!visit[v]) check(v) ;
      else if(visit[v]==1) isCycle=true ;
    visit[u]++ ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    adj.resize(n+1) ;
    visit.assign(n+1, 0) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x ;
        for(int j=0 ; j<x ; j++)
          {
            cin>> v ;
            adj[i].pb(v) ;
          }
      }
    cin>> s ;
    dfs(s, 0) ;
    check(s) ;
    if(ans.empty())
      {
        if(isCycle) cout<< "Draw" ;
        else cout<< "Lose" ;
      }
    else
      {
        cout<< "Win" << endl ;
        for(auto i:ans) cout<< i << " " ;
      }
  }
