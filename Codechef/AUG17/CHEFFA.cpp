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

int n, T ;
lli cnt, dp[51][151][151] ;
vi a ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        if(n==1)
          {
            cout<< 1 << endl ;
            continue ;
          }
        a.clear() ; a.resize(n+1) ;
        memset(dp, 0, sizeof dp) ;
        for(int i=0 ; i<n ; i++)
          cin>> a[i] ;
        for(int i=0 ; i<=150 ; i++)
          dp[n-2][i][0]=dp[n-2][0][i]=1 ;
        for(int i=1 ; i<=150 ; i++)
          for(int j=1 ; j<=150 ; j++)
            for(int k=0 ; k<=min(i, j) ; k++)
              dp[n-2][j][i]=(dp[n-2][j][i]+dp[n-2][i-k][k])%mod ;
        for(int x=n-3 ; x>=0 ; x--)
          for (int i=0 ; i<=150 ; i++)
            for (int j=0 ; j<=150 ; j++)
              for(int k=0 ; k<=min(i, j) ; k++)
                dp[x][j][i]=(dp[x][j][i]+dp[x+1][i-k][a[x+2]+k])%mod ;
        cout<< dp[0][a[0]][a[1]] << endl ;
      }
  }
