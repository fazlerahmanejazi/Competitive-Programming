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

int n, m, u, v, x, s, ans, dp[300030][3], deg[300030] ;
vvi adj ;

void init()
  {
    adj.clear() ;
    adj.resize(n+1) ;
    for(int i=1 ; i<=n ; i++) deg[i]=dp[i][0]=dp[i][1]=0 ;
    ans=0 ;
    s=-1 ;
  }

void dfs(int u, int prev)
  {
    dp[u][1]=deg[u]-1 ;
    int curr=deg[u]+1 ;
    vi temp ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs(v, u) ;
          if(deg[v]>1)
            {
              temp.pb(dp[v][1]) ;
              dp[u][1]=max(dp[u][1], deg[u]+dp[v][1]-1) ;
            }
          dp[u][0]=max(dp[u][0], dp[v][0]) ;
        }
    sort(all(temp)) ;
    reverse(all(temp)) ;
    if(temp.size()>=2) curr+=temp[0]+temp[1] ;
    else if(temp.size()==1) curr+=temp[0] ;
    dp[u][0]=max(dp[u][0], curr) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int q ;
    cin>> q ;
    while(q--)
      {
        cin>> n ;
        init() ;
        for(int i=1 ; i<n ; i++)
          {
            cin>> u >> v ;
            adj[u].pb(v) ;
            adj[v].pb(u) ;
            deg[u]++ ;
            deg[v]++ ;
          }
        if(n<=2)
          {
            cout<< n << endl ;
            continue ;
          }
        for(int i=1 ; i<=n ; i++) if(deg[i]!=1) s=i ;
        dfs(s, -1) ;
        cout<< dp[s][0] << endl ;
      }
  }
