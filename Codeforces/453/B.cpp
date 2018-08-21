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

int n, m, u, v, x, ans=1 ;
vvi adj ;
vi c ;

int dfs(int u, int prev, int col)
  {
    for(auto v:adj[u])
      if(v!=prev)
        {
          if(col!=c[v]) dfs(v, u, c[v]), ans++ ;
          else dfs(v, u, col) ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    c.resize(n+1) ;
    for(int i=2 ; i<=n ; i++)
      {
        cin>> x ;
        adj[i].pb(x) ;
        adj[x].pb(i) ;
      }
    for(int i=1 ; i<=n ; i++) cin>> c[i] ;
    dfs(1, -1, c[1]) ;
    cout<< ans ;
  }
