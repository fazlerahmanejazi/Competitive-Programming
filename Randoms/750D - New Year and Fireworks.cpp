#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod (lli)1000000007
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

int n, ans ;
vi t ;
bool cells[400][400], dp[400][400][31][8] ;

int dx[]={1, 1, 0, -1, -1, -1, 0, 1} ;
int dy[]={0, 1, 1, 1, 0, -1, -1, -1} ;

void dfs(int x, int y, int l, int dir)
  {
    if(l==n) return ;
    if(dp[x][y][l][dir]) return ;
    dp[x][y][l][dir]=true ;
    int X, Y, dir1, dir2 ;
    for(int i=0 ; i<t[l] ; i++)
      {
        X=x+i*dx[dir] ;
        Y=y+i*dy[dir] ;
        cells[Y][X]=true ;
      }
    dir1=dir-1 ;
    if(dir1==-1) dir1=7 ;
    dir2=dir+1 ;
    if(dir2==8) dir2=0 ;
    dfs(X+dx[dir1], Y+dy[dir1], l+1, dir1) ;
    dfs(X+dx[dir2], Y+dy[dir2], l+1, dir2) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    t.resize(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> t[i] ;
    memset(cells, false, sizeof cells) ;
    memset(dp, false, sizeof dp) ;
    dfs(200, 200, 0, 2) ;
    for(int i=0 ; i<400 ; i++)
      for(int j=0 ; j<400 ; j++)
        if(cells[i][j])
          ans++ ;
    cout<< ans ;
  }
