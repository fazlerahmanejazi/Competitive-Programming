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

int n, m, k, d, t, u, v ;
bool avail[110][550], pos ;
vpii F ;
vi s, R, cnt ;
vvi adj[110], ans ;

void init()
  {
    s.resize(k+1) ;
    ans.resize(k+1) ;
    cnt.assign(n+1, 0) ;
    for(int i=1 ; i<=n ; i++) R.pb(i) ;
    for(int i=1 ; i<=d ; i++) adj[i].resize(n+1) ;
    memset(avail, true, sizeof avail) ;
  }

void dfs(int u, int D, int idx)
  {
    if(D>d)
      {
        pos=true ;
        return ;
      }
    for(auto v:adj[D][u])
      if(avail[D][v])
        {
          avail[D][v]=false ;
          ans[idx].pb(v) ;
          dfs(v, D+1, idx) ;
          if(pos) return ;
          ans[idx].pop_back() ;
          avail[D][v]=true ;
        }
  }

void count(int u, int D, int idx)
  {
    if(D>d)
      {
        cnt[idx]++ ;
        return ;
      }
    for(auto v:adj[D][u]) count(v, D+1, idx) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> k >> d ;
    init() ;
    for(int i=1 ; i<=k ; i++) cin>> s[i] ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> u >> v >> t ;
        adj[t][u].pb(v) ;
      }
    for(int i=1 ; i<=k ; i++)
      {
        count(s[i], 1, i) ;
        F.pb(mp(cnt[i], i)) ;
      }
    sort(all(F)) ;
    for(auto f:F)
      {
        int i=f.se ;
        pos=false ;
        avail[0][s[i]]=false ;
        ans[i].pb(s[i]) ;
        dfs(s[i], 1, i) ;
      }
    for(int i=1 ; i<=k ; i++)
      {
        for(auto j:ans[i]) cout<< j << " " ;
        cout<< endl ;
      }
  }
