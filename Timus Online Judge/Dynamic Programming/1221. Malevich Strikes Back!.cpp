//This solution is slow

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

int n, ans, grid[105][105], dp[105][105][105][5][2] ;
int dx[]={1, -1, -1, 1}, dy[]={1, 1, -1, -1} ;
bool pos ;

void solve(int x, int y, int sz, int d, int t)
  {
    if(x<1 || y<1 || x>n || y>n || !sz) return ;
    if(dp[x][y][sz][d][t]!=-1) return ;
    solve(x+dx[d], y, sz-1, d, t) ;
    solve(x, y+dy[d], sz-1, d, t) ;
    solve(x+dx[d], y+dy[d], sz-1, d, t) ;
    if(grid[x][y]==t)
      {
        if(sz==1) dp[x][y][sz][d][t]=1 ;
        else if(x+dx[d]<=n && x+dx[d]>=1 && y+dy[d]<=n && y+dy[d]>=1 && dp[x+dx[d]][y][sz-1][d][t]==1 && dp[x][y+dy[d]][sz-1][d][t]==1) dp[x][y][sz][d][t]=1 ;
        else dp[x][y][sz][d][t]=0 ;
      }
    else dp[x][y][sz][d][t]=0 ;
    return ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    while(cin>> n && n)
      {
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=n ; j++)
            cin>> grid[i][j] ;
        ans=0 ;
        memset(dp, -1, sizeof dp) ;
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=1+n/2 ; j++)
            for(int k=0 ; k<4 ; k++)
              {
                dp[i][j][0][k][grid[i][j]]=1 ;
                dp[i][j][0][k][1-grid[i][j]]=0 ;
              }
        for(int i=1 ; i<=n ; i++)
          for(int j=0 ; j<2 ; j++)
            {
              solve(1, 1, i, 0, j) ;
              solve(n, 1, i, 1, j) ;
              solve(n, n, i, 2, j) ;
              solve(1, n, i, 3, j) ;
            }
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=n ; j++)
            for(int k=1 ; k<=n ; k++)
              if(i-k>=1 && i+k<=n && j-k>=1 && j+k<=n)
                {
                  pos=true ;
                  for(int l=0 ; l<4 ; l++)
                    {
                      pos&=max(dp[i][j][k+1][l][0], 0) ;
                      pos&=max(dp[i-dx[l]*k][j-dy[l]*k][k][l][1], 0) ;
                    }
                  if(pos) ans=max(ans, 2*k+1) ;
                }
        if(ans) cout<< ans << endl ;
        else cout<< "No solution" << endl ;
      }
  }
