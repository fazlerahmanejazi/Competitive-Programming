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

lli n, u, v, s, curr, ans=INF, res[100005], c[4][100005], dp[100005][4][4] ;
vlli a ;
vvi adj(100005) ;
bool pos=true ;

void dfs(int u, int prev)
  {
    a.pb(u) ;
    for(auto v:adj[u]) if(v!=prev) dfs(v, u) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=3 ; i++)
      for(int j=1 ; j<=n ; j++)
        cin>> c[i][j] ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    for(int i=1 ; i<=n ; i++)
      if(adj[i].size()>2)
        pos=false ;
      else if(adj[i].size()==1)
        s=i ;
    if(pos)
      {
        a.pb(0) ;
        dfs(s, -1) ;
        for(int i=1 ; i<=3 ; i++)
          for(int j=1 ; j<=3 ; j++)
            if(i!=j)
              {
                dp[1][i][j]=c[i][a[1]] ;
                dp[2][i][j]=c[i][a[2]]+min({dp[1][j][1], dp[1][j][2], dp[1][j][3]}) ;
              }
        for(int i=3 ; i<=n ; i++)
          for(int j=1 ; j<=3 ; j++)
            for(int k=1 ; k<=3 ; k++)
              if(j!=k)
                for(int l=1 ; l<=3 ; l++)
                  if(l!=j && l!=k)
                    dp[i][j][k]=c[j][a[i]]+dp[i-1][k][l] ;
        for(int i=1 ; i<=3 ; i++)
          for(int j=1 ; j<=3 ; j++)
            if(i!=j)
              ans=min(ans, dp[n][i][j]) ;
        cout<< ans ;
        for(int i=1 ; i<=3 ; i++)
          for(int j=1 ; j<=3 ; j++)
            if(i!=j && ans==dp[n][i][j])
              {
                int x, y=j, z=i, lim=n- ;
                while()
              }
      }
    else cout<< -1 ;
  }
