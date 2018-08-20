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

int n, m, u, v ;
vi d, ans ;
vvi adj ;
vector<map<int, int>> cnt ;

void init()
  {
    adj.resize(n+1) ;
    cnt.resize(n+1) ;
    d.assign(n+1, 0) ;
    ans.assign(n+1, 0) ;
  }

void dfs(int u, int prev)
  {
    d[u]=d[prev]+1 ;
    ans[u]=d[u] ;
    cnt[u][d[u]]++ ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs(v, u) ;
          if(cnt[u].size()<cnt[v].size()) swap(cnt[u], cnt[v]), ans[u]=ans[v] ;
          for(auto x:cnt[v])
            {
              cnt[u][x.fi]+=x.se ;
              if(cnt[u][x.fi]+(x.fi<ans[u])>cnt[u][ans[u]]) ans[u]=x.fi ;
            }
          cnt[v].clear() ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    init() ;
    for(int i=1 ; i<n ; i++) cin>> u >> v, adj[u].pb(v), adj[v].pb(u) ;
    dfs(1, 0) ;
    for(int i=1 ; i<=n ; i++) cout<< ans[i]-d[i] << endl ;
  }
