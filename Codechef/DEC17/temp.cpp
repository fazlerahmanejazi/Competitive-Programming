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

lli T, n, q, u, v, x, k, a, b, t ;
vlli val, f ;
vvi adj ;

void init()
  {
    adj.clear() ; adj.resize(n+1) ;
    val.assign(n+1, 0) ;
    f.clear() ; f.resize(n+1) ;
  }

void dfs(int u, int d, int prev)
  {
    if(d>k) return ;
    if(d>1) f[d]=(f[d-1]+f[d-2])%mod ;
    val[u]=(val[u]+f[d])%mod ;
    for(auto v:adj[u]) if(v!=prev) dfs(v, d+1, u) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> q ;
        init() ;
        for(int i=1 ; i<n ; i++)
          {
            cin>> u >> v ;
            adj[u].pb(v) ;
            adj[v].pb(u) ;
          }
        for(int i=1 ; i<=q ; i++)
          {
            cin>> t ;
            if(t==1)
              {
                cin>> v >> k >> a >> b ;
                f[0]=a ; f[1]=b ;
                dfs(v, 0, -1) ;
              }
            else
              {
                cin>> v ;
                cout<< val[v] << endl ;
              }
          }
      }
  }
