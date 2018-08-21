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
    lli m, grid[2][100005], dp[2][2][100005] ;
    cin>> m ;
    for(int i=0 ; i<2 ; i++) for(int j=0 ; j<m ; j++) cin>> grid[i][j] ;
    dp[0][0][m-1]=dp[1][0][m-1]=grid[0][m-1]+grid[1][m-1] ;
    dp[0][1][m-1]=dp[1][1][m-1]=grid[1][m-1] ;
    for(int i=m-2 ; i>=0 ; i--)
      {
        dp[0][0][i]=grid[0][i]+max(dp[1][0][i+1], grid[1][i]+dp[0][1][i+1]) ;
        dp[1][0][i]=grid[0][i]+min(dp[0][0][i+1], grid[1][i]+dp[1][1][i+1]) ;
        dp[0][1][i]=grid[1][i]+max(dp[1][1][i+1], grid[0][i]+dp[0][0][i+1]) ;
        dp[1][1][i]=grid[1][i]+min(dp[0][1][i+1], grid[0][i]+dp[1][0][i+1]) ;
      }
    cout<< dp[1][0][0] ;
  }
