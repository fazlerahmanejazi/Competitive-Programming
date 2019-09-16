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

lli T, n, u, v, ans, a[100010], dp1[100010], dp2[100010], dp3[100010] ;
vvi adj ;

void init()
  {
    ans=0 ;
    adj.clear() ;
    adj.resize(n+1) ;
    memset(dp1, 0, sizeof dp1) ;
    memset(dp2, 0, sizeof dp2) ;
    memset(dp3, 0, sizeof dp3) ;
  }

void dfs(int u, int prev)
  {
    dp1[u]=-INF ;
    dp2[u]=max(a[u], 0LL) ;
    dp3[u]=0 ;
    bool is_leaf=true ;
    vlli temp1, temp2, temp3 ;
    lli curr=0 ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          is_leaf=false ;
          dfs(v, u) ;
          dp1[u]=max(dp1[v]+a[u], dp1[u]) ;
          dp2[u]=max({dp1[v]+a[u], dp1[v], dp2[v], dp2[u]}) ;
          dp3[u]=max({dp3[v]+a[u], a[u], dp3[u]}) ;
          temp1.pb(dp1[v]) ;
          temp2.pb(dp2[v]) ;
          temp3.pb(dp3[v]) ;
        }
    if(is_leaf) dp1[u]=a[u] ;
    else
      {
        curr=0 ;
        sort(all(temp1)) ;
        reverse(all(temp1)) ;
        curr+=temp1[0] ;
        if(temp1.size()>=2) curr+=temp1[1] ;
        ans=max(ans, curr) ;
        //
        curr=max(a[u], 0LL) ;
        sort(all(temp2)) ;
        reverse(all(temp2)) ;
        curr+=temp2[0] ;
        if(temp2.size()>=2) curr+=temp2[1] ;
        ans=max(ans, curr) ;
      }
    ans=max({ans, dp1[u], dp2[u]}) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        init() ;
        for(int i=1 ; i<=n ; i++) cin>> a[i] ;
        for(int i=1 ; i<n ; i++)
          {
            cin>> u >> v ;
            adj[u].pb(v) ;
            adj[v].pb(u) ;
          }
        dfs(1, -1) ;
        cout<< ans << endl ;
      }
  }
