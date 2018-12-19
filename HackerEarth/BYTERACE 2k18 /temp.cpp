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

lli n, m, x, X, Y ;
lli grid[25][25] ;
set<lli> cnt[25][25][2], ans ;

void solve(int x, int y, lli curr, int d, int t)
  {
    if(x>n || y>m || x<0 || y<0) return ;
    if(x+y-1==max(n, m))
      {
        cnt[x][y][t].insert(curr) ;
        return ;
      }
    solve(x+d, y, curr^grid[x+d][y], d, t) ;
    solve(x, y+d, curr^grid[x][y+d], d, t) ;
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        cin>> grid[i][j] ;
    solve(1, 1, grid[1][1], 1, 1) ;
    solve(n, m, grid[n][m], -1, 0) ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        for(auto k:cnt[i][j][0])
          for(auto l:cnt[i][j][1])
            ans.insert(k^l) ;
    cout<< ans.size() ;
  }
