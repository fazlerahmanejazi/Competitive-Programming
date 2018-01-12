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

int n, k, u, v ;
vvi adj ;
vi dist ;
vector<long double> ans ;
long double tot ;

void dfs(int u, int prev, int d, long double p)
  {
    dist[u]=d ;
    int c=0 ;
    long double curr ;
    for(int i=0 ; i<adj[u].size() ; i++)
      {
        int v=adj[u][i] ;
        if(v!=prev) c++ ;
      }
    if(c) curr=p*(1/(c*1.0)) ;
    for(int i=0 ; i<adj[u].size() ; i++)
      {
        int v=adj[u][i] ;
        if(v!=prev)
          {
            dfs(v, u, d+1, curr) ;
            c++ ;
          }
      }
    if(c==0) ans.pb(p*(1.0*d)) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    dist.resize(n+1) ;
    for(int i=0 ; i<n-1 ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs(1, -1, 0, 1) ;
    tot=0 ;
    for(int i=0 ; i<ans.size() ; i++)
      tot+=ans[i] ;
    cout<< fixed << setprecision(9) << tot ;
  }
