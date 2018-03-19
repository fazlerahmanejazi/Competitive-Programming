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

int n, m, u, v, x, mx, ans, dp[300005][27] ;
bool isCycle ;
string s ;
vvi adj ;
vi visit, topo ;

void check(int u, int prev)
  {
    visit[u]++ ;
    for(auto v:adj[u])
      if(!visit[v]) check(v, u) ;
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
    cin>> n >> m >> s ;
    adj.resize(n+1) ;
    visit.assign(n+1, 0) ;
    s='#'+s ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        if(u==v) isCycle=true ;
      }
    if(!isCycle) for(int i=1 ; i<=n ; i++) if(!visit[i]) check(i, -1) ;
    if(isCycle)
      {
        cout<< -1 ;
        return 0 ;
      }
    visit.assign(n+1, 0) ;
    for(int i=1 ; i<=n ; i++) if(!visit[i]) dfs(i) ;
    for(auto u:topo)
      {
        dp[u][s[u]-'a']=1 ;
        for(auto v:adj[u])
          for(int i=0 ; i<26 ; i++)
            if(i==s[u]-'a') dp[u][i]=max(dp[u][i], dp[v][i]+1) ;
            else dp[u][i]=max(dp[u][i], dp[v][i]) ;
        for(int i=0 ; i<26 ; i++) ans=max(ans, dp[u][i]) ;
      }
    cout<< ans ;
  }
