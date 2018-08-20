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

lli n, m, a, b, u, v, x, ans ;
vi c ;
vvi adj ;
vector<priority_queue<lli>> cnt ;

void init()
  {
    ans=0 ;
    adj.clear() ; cnt.clear() ; c.clear() ;
    adj.resize(n) ; cnt.resize(n) ; c.assign(n, 0) ;
    for(int i=0 ; i<m ; i++) c[(a*i+b)%n]++ ;
  }

void dfs(int u, int prev)
  {
    cnt[u].push(u) ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs(v, u) ;
          if(cnt[u].size()<cnt[v].size()) swap(cnt[u], cnt[v]) ;
          while(!cnt[v].empty()) cnt[u].push(cnt[v].top()), cnt[v].pop() ;
        }
    while(c[u]-- && !cnt[u].empty()) ans+=cnt[u].top(), cnt[u].pop() ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> n >> m >> a >> b ;
        init() ;
        for(int i=1 ; i<n ; i++) cin>> x, adj[i].pb(x), adj[x].pb(i) ;
        dfs(0, -1) ;
        cout<< "Case #" << tc << ": " << ans<< endl ;
      }
  }
