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

lli curr ;
vlli ans ;
int n, m, k, x, y, c ;
char grid[1010][1010] ;
int visit[1010][1010] ;

int dx[]={1, 0, -1 , 0}, dy[]={0, 1, 0, -1} ;

void dfs(int x, int y, int c)
  {
    visit[x][y]=c ;
    for(int i=0 ; i<4 ; i++)
      if(grid[x+dx[i]][y+dy[i]]=='.' && !visit[x+dx[i]][y+dy[i]]) dfs(x+dx[i], y+dy[i], c) ;
      else if(grid[x+dx[i]][y+dy[i]]=='*') curr++ ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> k ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        cin>> grid[i][j] ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        if(!visit[i][j] && grid[i][j]=='.')
          {
            curr=0 ;
            dfs(i, j, ++c) ;
            ans.pb(curr) ;
          }
    for(int i=0 ; i<k ; i++)
      {
        cin>> x >> y ;
        cout<< ans[visit[x][y]-1] << endl ;
      }
  }
