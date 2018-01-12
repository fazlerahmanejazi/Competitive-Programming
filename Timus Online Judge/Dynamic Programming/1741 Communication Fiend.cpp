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

int n, m, x, y, d ;
lli dp[10005][3], ans ;
string s ;
vector<vector<tuple<int, int, int>>> adj ;

int type(char c)
  {
    if(c=='P') return 0 ;
    else if(c=='C') return 1 ;
    else return 2 ;
  }

void dfs(int u, lli val, int type)
  {
    if(val>dp[u][type]) return ;
    else dp[u][type]=val ;
    int v, d, t ;
    for(int i=0 ; i<adj[u].size() ; i++)
      {
        tie(v, d, t)=adj[u][i] ;
        if(!type && t!=2) dfs(v, val+d, type) ;
        else if(type) dfs(v, val+d, min(1, type*t)) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    adj.resize(n+1) ;
    for(int i=0 ; i<=n ; i++) for(int j=0 ; j<=2 ; j++) dp[i][j]=INF ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> x >> y >> d >> s ;
        adj[x].pb(mt(y, d, type(s[0]))) ;
      }
    dfs(1, 0, 1) ;
    ans=min({dp[n][0], dp[n][1], dp[n][2]}) ;
    if(ans!=INF) cout<< "Online" << endl << ans ;
    else cout<< "Offline" ;
  }
