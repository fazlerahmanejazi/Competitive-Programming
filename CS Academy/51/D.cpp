#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

lli n, u, v, k, res ;
vvi adj ;

void dfs(int u, int prev)
  {
    lli c=2 ;
    if(u==1) c-- ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          res*=(k-c) ;
          res%=mod ;
          c++ ;
          dfs(v, u) ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    adj.resize(n+1) ;
    for(int i=0 ; i<n-1 ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    res=k ;
    dfs(1, -1) ;
    cout<< res ;
  }
