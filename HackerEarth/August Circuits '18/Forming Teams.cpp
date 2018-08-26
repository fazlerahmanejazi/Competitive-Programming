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

lli n, k, x, u, v, l, r, m, tc=1, ans, dp[1010][1010], a[1010], visit[1010][1010] ;
vvi adj ;

void dfs(int u, int p, int leader, int maxDiff)
  {
    if(visit[u][leader]==tc) return ;
    visit[u][leader]=tc ;
    lli res=0, curr ;
    for(auto v:adj[u])
      if(v!=p)
        {
          curr=inf ;
          if(abs(a[v]-a[leader])<=maxDiff)
            {
              dfs(v, u, leader, maxDiff) ;
              curr=min(curr, dp[v][leader]) ;
            }
          dfs(v, u, v, maxDiff) ;
          curr=min(curr, dp[v][v]+1) ;
          res+=curr ;
        }
    dp[u][leader]=res ;
  }

lli get(int m)
  {
    tc++ ;
    dfs(1, -1, 1, m) ;
    return dp[1][1]+1 ;
  }

int solve()
  {
    tie(l, r, ans)=mt(0, 1e9, 1e9) ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        if(get(m)<=k) r=m-1, ans=m ;
        else l=m+1 ;
      }
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> k ;
        adj.clear() ; adj.resize(n+1) ;
        for(int i=1 ; i<=n ; i++) cin>> a[i] ;
        for(int i=1 ; i<n ; i++)
          {
            cin>> u >> v ;
            adj[u].pb(v) ;
            adj[v].pb(u) ;
          }
        cout<< solve() << endl ;
      }
  }
