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

int n, m, q, x, X, y, Y, cnt ;
int grid[2010][2010] ;
bool visit[2010][2010] ;
char c ;

void dfs(int i, int j)
  {
    visit[i][j]=true ;
    if(i-1>=x && grid[i-1][j] && !visit[i-1][j]) dfs(i-1, j) ;
    if(i+1<=X && grid[i+1][j] && !visit[i+1][j]) dfs(i+1, j) ;
    if(j-1>=y && grid[i][j-1] && !visit[i][j-1]) dfs(i, j-1) ;
    if(j+1<=Y && grid[i][j+1] && !visit[i][j+1]) dfs(i, j+1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> q ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        {
          cin>> c ;
          grid[i][j]=c-'0' ;
        }
    for(int k=0 ; k<q ; k++)
      {
        cnt=0 ;
        memset(visit, 1, sizeof visit) ;
        for(int i=0 ; i<n ; i++)
          for(int j=0 ; j<m ; j++)
            if(grid[i][j])
              visit[i][j]=0 ;
        cin>> x >> y >> X >> Y ;
        if(X<x) swap(x, X) ;
        if(Y<y) swap(y, Y) ;
        x-- ; X-- ; y-- ; Y-- ;
        for(int i=x ; i<=X ; i++)
          for(int j=y ; j<=Y ; j++)
            if(!visit[i][j] && grid[i][j])
              {
                cnt++ ;
                dfs(i, j) ;
              }
        cout<< cnt << endl ;
      }
    }
