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
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m, x, y, b, w ;
    cin>> n >> m >> x >> y ;
    vi sumW(m+1, 0), sumB(m+1, 0) ;
    char picture[n][m] ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        cin>> picture[i][j] ;
    for(int j=1 ; j<=m ; j++)
      {
        b=w=0 ;
        for(int i=0 ; i<n ; i++)
          if(picture[i][j-1]=='.') w++ ;
          else b++ ;
        sumW[j]=sumW[j-1]+w ;
        sumB[j]=sumB[j-1]+b ;
      }
    int dp[2][m+1] ;
    memset(dp, inf, sizeof dp) ;
    dp[0][0]=dp[1][0]=0 ;
    for(int i=x ; i<=m ; i++)
      for(int j=x; j<=min(y, i) ; j++)
        {
          dp[0][i]=min(dp[0][i], dp[1][i-j]+sumW[i]-sumW[i-j]) ;
          dp[1][i]=min(dp[1][i], dp[0][i-j]+sumB[i]-sumB[i-j]) ;
        }
    cout<< min(dp[0][m], dp[1][m]) ;
  }
