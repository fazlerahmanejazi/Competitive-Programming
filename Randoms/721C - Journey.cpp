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

int n, m, T, u, v, t ;
vector<vpii> adj ;
vi path, ans ;
vb visit ;
int dp[5005][5005] ;

void init()
  {
    adj.resize(n+1) ;
    visit.assign(n+1, false) ;
    memset(dp, inf, sizeof dp) ;
  }

void dfs(int u, int t, int c)
  {
    if(dp[u][c]<t) return ;
    if(u==n && t<=T && path.size()+1>ans.size())
      {
        ans=path ;
        ans.pb(n) ;
        return ;
      }
    dp[u][c]=t ;
    visit[u]=true ;
    path.pb(u) ;
    for(int i=0 ; i<adj[u].size() ; i++)
      {
        int v=adj[u][i].fi, w=adj[u][i].se ;
        if(!visit[v] && t+w<=T)
          dfs(v, t+w, c+1) ;
      }
    path.pop_back() ;
    visit[u]=false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> T ;
    init() ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> u >> v >> t ;
        adj[u].pb(mp(v, t)) ;
      }
    dfs(1, 0, 0) ;
    cout<< ans.size() << endl ;
    for(int i=0 ; i<ans.size() ; i++)
      cout<< ans[i] << " " ;
  }
