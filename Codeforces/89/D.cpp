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
    int n1, n2, k1, k2, dp[110][110][2], m=100000000 ;
    cin>> n1 >> n2 >> k1 >> k2 ;
    memset(dp, 0, sizeof dp) ;
    for(int i=1 ; i<=k1 ; i++) dp[i][0][1]=1 ;
    for(int i=1 ; i<=k2 ; i++) dp[0][i][0]=1 ;
    for(int i=1 ; i<=n1 ; i++)
      for(int j=1 ; j<=n2 ; j++)
        {
          for(int k=1 ; k<=min(i, k1) ; k++) dp[i][j][1]=(dp[i][j][1]+dp[i-k][j][0])%m ;
          for(int k=1 ; k<=min(j, k2) ; k++) dp[i][j][0]=(dp[i][j][0]+dp[i][j-k][1])%m ;
        }
    cout<< (dp[n1][n2][0]+dp[n1][n2][1])%m ;
  }
