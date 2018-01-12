#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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
    while(T--)
      {
        int n, x, y ;
        cin>> n ;
        vi a(n+1) ;
        for(int i=1 ; i<=n ; i++)
          cin>> a[i] ;
        pii dp[n+1][n+1] ;
        for(int i=1 ; i<=n ; i++)
          {
            dp[i][i].fi=a[i] ;
            dp[i][i].se=0 ;
          }
        for(int len=1 ; len<=n ; len++)
          for(int j=1 ; j+len<=n ; j++)
            {
              x=dp[j][j+len-1].se+a[j+len] ;
              y=a[j]+dp[j+1][j+len].se ;
              if(x>y)
                {
                  dp[j][j+len].fi=x ;
                  dp[j][j+len].se=dp[j][j+len-1].fi ;
                }
              else
                {
                  dp[j][j+len].fi=y ;
                  dp[j][j+len].se=dp[j+1][j+len].fi ;
                }
            }
        cout<< dp[1][n].fi-dp[1][n].se << endl ;
      }
  }
