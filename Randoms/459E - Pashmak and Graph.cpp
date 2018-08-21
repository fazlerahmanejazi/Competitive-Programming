#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define PI 3.1415926535897932384626433832795
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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m, u, v, w ;
    cin>> n >> m ;
    vi dp(n+1, 0) ;
    vector<vpii> edges(100000+5) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> u >> v >> w ;
        edges[w].pb(mp(u, v)) ;
      }
    for(int i=1 ; i<=100000 ; i++)
      {
        vi a ;
        for(int j=0 ; j<edges[i].size() ; j++)
          {
            tie(u, v)=edges[i][j] ;
            a.pb(dp[u]+1) ;
          }
        for(int j=0 ; j<edges[i].size() ; j++)
          {
            tie(u, v)=edges[i][j] ;
            dp[v]=max(dp[v], a[j]) ;
          }
      }
    cout<< *max_element(all(dp)) ;
  }
