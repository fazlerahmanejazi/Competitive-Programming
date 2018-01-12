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

lli n, u, v, x, k, ans ;
vector<vector<tuple<lli, lli, lli>>> adj ;
vlli a, b ;

void init()
  {
    a.resize(n+1) ;
    b.resize(n+1) ;
    adj.resize(n+1) ;
  }

lli calc(lli p, lli q)
  {
    if(p>INF/(-q)) return -INF ;
    else return p*q ;
  }

lli dfs(int u, int prev)
  {
    lli x, v, next, y ;
    for(auto t:adj[u])
      {
        tie(v, x, y)=t ;
        if(v==prev) continue ;
        next=dfs(v, u) ;
        if(next<0) a[u]+=calc(x, next), a[u]=max(a[u], -INF) ;
        else a[u]+=next/y ;
      }
    return max(a[u]-b[u], -INF) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    init() ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=1 ; i<=n ; i++) cin>> b[i] ;
    for(int i=2 ; i<=n ; i++)
      {
        cin>> x >> k ;
        adj[x].pb(mt(i, k, 1)) ;
        adj[i].pb(mt(x, 1, k)) ;
      }
    ans=dfs(1, -1) ;
    if(ans<0) cout<< "NO" ;
    else cout<< "YES" ;
  }
