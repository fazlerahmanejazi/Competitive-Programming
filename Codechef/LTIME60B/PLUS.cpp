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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        int n, m, ans=INT_MIN, curr, grid[1010][1010], r[1010][1010], l[1010][1010], u[1010][1010], d[1010][1010] ;
        cin>> n >> m ;
        for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++) cin>> grid[i][j] ;
        for(int i=1 ; i<=n ; i++)
          {
            l[i][1]=grid[i][1] ;
            for(int j=2 ; j<=m ; j++) l[i][j]=max(grid[i][j], l[i][j-1]+grid[i][j]) ;
            r[i][m]=grid[i][m] ;
            for(int j=m-1 ; j>=1 ; j--) r[i][j]=max(grid[i][j], r[i][j+1]+grid[i][j]) ;
          }
        for(int i=1 ; i<=m ; i++)
          {
            u[1][i]=grid[1][i] ;
            for(int j=2 ; j<=n ; j++) u[j][i]=max(grid[j][i], u[j-1][i]+grid[j][i]) ;
            d[n][i]=grid[n][i] ;
            for(int j=n-1 ; j>=1 ; j--) d[j][i]=max(grid[j][i], d[j+1][i]+grid[j][i]) ;
          }
        for(int i=2 ; i<n ; i++)
          for(int j=2 ; j<m ; j++)
            ans=max(ans, grid[i][j]+l[i][j-1]+r[i][j+1]+u[i-1][j]+d[i+1][j]) ;
        cout<< ans << endl ;
      }
  }
