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
    lli t, n, m, k, dp[31][31][51], x, y, z ;
    memset(dp, INF, sizeof dp) ;
    dp[0][0][0]=0 ;
    for(int i=1 ; i<=30 ; i++)
      for(int j=1 ; j<=30 ; j++)
        if(j<i) dp[i][1][j]=dp[1][i][j]=1 ;
        else if(j==i) dp[i][1][j]=dp[1][i][j]=0 ;
        else dp[i][1][j]=dp[1][i][j]=INF ;
    for(int i=2 ; i<=30 ; i++)
      for(int j=2 ; j<=30 ; j++)
        for(int k=1 ; k<=50 ; k++)
          if(k>i*j) dp[i][j][k]=INF ;
          else if(k==i*j) dp[i][j][k]=0 ;
          else
            {
              x=y=INF ;
              for(int l=1 ; l<=j-1 ; l++)
                {
                  x=min({x, dp[i][j-l][k], dp[i][l][k]}) ;
                  if(k>=l*i) x=min(x, dp[i][j-l][k-l*i]) ;
                  if(k>=(j-l)*i) x=min(x, dp[i][l][k-(j-l)*i]) ;
                }
              for(int l=1 ; l<=i-1 ; l++)
                {
                  y=min({y, dp[i-l][j][k], dp[l][j][k]}) ;
                  if(k>=l*j) y=min(y, dp[i-l][j][k-l*j]) ;
                  if(k>=(i-l)*j) y=min(y, dp[l][j][k-(i-l)*j]) ;
                }
              dp[i][j][k]=min(x+i*i, y+j*j) ;
            }
    cin>> t ;
    while(t--)
      {
        cin>> n >> m >> k ;
        cout<< dp[n][m][k] << endl ;
      }
  }
