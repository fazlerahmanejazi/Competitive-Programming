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

lli n, m, K, x, X, Y, ans ;
lli grid[25][25] ;
map<lli, lli> cnt[25][25] ;

void solve(int x, int y, lli curr, int d)
  {
    if(x>n || y>m || x<0 || y<0) return ;
    if(x+y-1==max(n, m))
      {
        if(d==1) cnt[x][y][curr]++ ;
        else ans+=cnt[x][y][curr^K^grid[x][y]] ;
        return ;
      }
    solve(x+d, y, curr^grid[x+d][y], d) ;
    solve(x, y+d, curr^grid[x][y+d], d) ;
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> K ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        cin>> grid[i][j] ;
    solve(1, 1, grid[1][1], 1) ;
    solve(n, m, grid[n][m], -1) ;
    cout<< ans ;
  }
