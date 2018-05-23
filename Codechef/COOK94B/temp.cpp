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

lli n, m ;
char grid[500][500] ;
lli count[500][500][3] ;

lli solve(lli x, lli y, lli t)
  {
    if(count[x][y][t]!=-1) return count[x][y][t] ;
    lli curr=0 ;
    if(t!=0 && x+1<=n) curr+=solve(x+1, y, 1) ;
    if(t!=1 && x-1>=1) curr+=solve(x-1, y, 0) ;
    curr+=solve(x, y+1, 2) ;
    curr+=solve(x, y+1, 2) ;
    return count[x][y][t]=curr ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> n >> m ;
        for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++) cin>> grid[i][j] ;
        for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++) for(int k=0 ; k<3 ; k++) count[i][j][k]=-1 ;
      }
  }
