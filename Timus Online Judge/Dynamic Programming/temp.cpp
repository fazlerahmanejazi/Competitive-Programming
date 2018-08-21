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

int n, u, v, x, s, dp[100005] ;
vvi adj ;

void dfs(int u, int prev)
  {
    vi temp ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs(v, u) ;
          temp.pb(dp[v]) ;
        }
    sort(all(temp)) ;
    reverse(all(temp)) ;
    for(int i=0 ; i<temp.size() ; i++) dp[u]=max(dp[u], temp[i]+i+1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    for(int i=1 ; i<=n ; i++)
      while(cin>> x && x)
        adj[i].pb(x), adj[x].pb(i) ;
    cin>> s ;
    dfs(s, -1) ;
    cout<< dp[s] ;
  }
