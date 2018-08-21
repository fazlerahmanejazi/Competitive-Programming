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

int n, k, x, ans=-1 ;
bool check ;
vvi adj ;
vi dp ;
vb visit ;

void dfs(int u)
  {
    visit[u]=true ;
    for(int i=0 ; i<adj[u].size() ; i++)
      {
        int v=adj[u][i] ;
        if(!visit[v])
          dfs(v) ;
        dp[u]=max(dp[u], dp[v]+1) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    vvi idx(k+1, vi(n+1)) ;
    adj.resize(n+1) ;
    dp.assign(n+1, 1) ;
    visit.assign(n+1, false) ;
    for(int i=1 ; i<=k ; i++)
      for(int j=1 ; j<=n ; j++)
        {
          cin>> x ;
          idx[i][x]=j ;
        }
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=n ; j++)
        if(i!=j)
          {
            check=true ;
            for(int l=1 ; l<=k ; l++)
              if(idx[l][i]>=idx[l][j])
                check=false ;
            if(check) adj[i].pb(j) ;
          }
    for(int i=1 ; i<=n ; i++)
      if(!visit[i])
        dfs(i) ;
    for(int i=1 ; i<=n ; i++)
      ans=max(ans, dp[i]) ;
    cout<< ans ;
  }
