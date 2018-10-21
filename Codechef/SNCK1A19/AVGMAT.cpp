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

int n, m, x, y, mx, offset=700, grid[1600][1600], ans[1000], dp[1600][1600][5] ;
char c ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        memset(ans, 0, sizeof ans) ;
        memset(grid, 0, sizeof grid) ;
        memset(dp, 0, sizeof dp) ;
        cin>> n >> m ;
        mx=n+m-2 ;
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=m ; j++)
            cin>> c, grid[i+offset][j+offset]=c-'0' ;
        n=m=1500 ;
        for(int i=1 ; i<=n ; i++)
          {
            x=i ; y=1 ;
            dp[x][y][1]=grid[x++][y++] ;
            while(x<=n && y<=m) dp[x][y][1]=dp[x-1][y-1][1]+grid[x++][y++] ;
            x=i ; y=1 ;
            dp[x][y][2]=grid[x--][y++] ;
            while(x>=1 && y<=m) dp[x][y][2]=dp[x+1][y-1][2]+grid[x--][y++] ;
          }
        for(int i=2 ; i<=m ; i++)
          {
            x=1 ; y=i ;
            dp[x][y][1]=grid[x++][y++] ;
            while(x<=n && y<=m) dp[x][y][1]=dp[x-1][y-1][1]+grid[x++][y++] ;
            x=n ; y=i ;
            dp[x][y][2]=grid[x--][y++] ;
            while(x>=1 && y<=m) dp[x][y][2]=dp[x+1][y-1][2]+grid[x--][y++] ;
          }
        for(int i=1 ; i<=m ; i++) dp[0][i][2]+=dp[1][i-1][2], dp[n+1][i][1]+=dp[n][i-1][1] ;
        for(int i=1 ; i<=n ; i++) dp[i][m+1][2]+=dp[i+1][m][2], dp[i][m+1][1]+=dp[i-1][m][1] ;
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=m ; j++)
            if(grid[i][j])
              for(int k=1 ; k<=mx ; k++)
                {
                  ans[k]+=(dp[i-k][j][2]-dp[i][j-k][2]) ;
                  ans[k]+=(dp[i][j+k][2]-dp[i+k][j][2]) ;
                  ans[k]+=(dp[i+k][j][1]-dp[i][j-k][1]) ;
                  ans[k]+=(dp[i][j+k][1]-dp[i-k][j][1]) ;
                }
        for(int i=1 ; i<=mx ; i++) cout<< ans[i]/2 << " " ;
        cout<< endl ;
      }
  }
