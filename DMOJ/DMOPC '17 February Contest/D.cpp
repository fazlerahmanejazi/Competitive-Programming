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

lli n, u, v, c, s=1, mx, ans, check, S, E ;
vector<vpii> adj ;

void dfs(int u, int prev, lli far)
  {
    if(far>mx) mx=far, s=u ;
    for(auto v:adj[u]) if(v.fi!=prev) dfs(v.fi, u, far+v.se) ;
    if(check && u!=E) ans=max(ans, far) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v >> c ;
        adj[u].pb(mp(v, c)) ;
        adj[v].pb(mp(u, c)) ;
      }
    dfs(s, -1, 0) ;
    S=s ; mx=0 ;
    dfs(s, -1, 0) ;
    E=s ; mx=0 ;
    check=true ;
    dfs(S, -1, 0) ;
    mx=0 ; swap(S, E) ;
    dfs(S, -1, 0) ;
    cout<< ans ;
  }
