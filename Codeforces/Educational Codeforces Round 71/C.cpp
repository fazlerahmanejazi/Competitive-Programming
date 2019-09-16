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

lli t, n, a, b, dp[200200][5], check[200200] ;
string s ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> t ;
    while(t--)
      {
        cin>> n >> a >> b >> s ;
        for(int i=1 ; i<=n ; i++) check[i]=s[i-1]-'0' ;
        dp[0][0]=b ; dp[0][1]=INF ;
        for(int i=1 ; i<=n ; i++)
          if(check[i])
            {
              dp[i][1]=dp[i-1][1]+a+2*b ;
              dp[i][0]=INF ;
            }
          else
            {
              dp[i][0]=min(dp[i-1][0]+a+b, dp[i-1][1]+2*a+b) ;
              dp[i][1]=min(dp[i-1][0]+2*a+2*b, dp[i-1][1]+a+2*b) ;
            }
        cout<< dp[n][0] << endl ;
      }
  }
