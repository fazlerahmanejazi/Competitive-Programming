#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int n, m, u, v, x ;
long long int ans ;
vb visit ;
vvi adj ;
vi cnt ;

void dfs(int t, int len, int prev)
  {
    if(len==2)
      {
        cnt[t]++ ;
        return ;
      }
    for(int i=0 ; i<adj[t].size() ; i++)
      if(adj[t][i]!=prev)
        dfs(adj[t][i], len+1, t) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    adj.resize(n+1) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
      }
    for(int i=1 ; i<=n ; i++)
      {
        cnt.assign(n+1, 0) ;
        dfs(i, 0, -1) ;
        for(int j=1 ; j<=n ; j++)
          if(cnt[j]>1)
            {
              x=cnt[j] ;
              ans+=(x*(x-1))/2 ;
            }
      }
    cout<< ans ;
  }
