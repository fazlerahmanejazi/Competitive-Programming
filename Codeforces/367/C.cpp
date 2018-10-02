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
    lli n, dp[100010][2], ans ;
    cin>> n ;
    vector<string> s(n), r(n) ;
    vlli c(n) ;
    for(int i=0 ; i<n ; i++) cin>> c[i] ;
    for(int i=0 ; i<n ; i++) cin>> s[i], r[i]=s[i], reverse(all(r[i])) ;
    dp[0][0]=0 ;
    dp[0][1]=c[0] ;
    for(int i=1 ; i<n ; i++)
      {
        dp[i][0]=dp[i][1]=INF ;
        if(s[i-1]<=s[i]) dp[i][0]=min(dp[i-1][0], dp[i][0]) ;
        if(r[i-1]<=s[i]) dp[i][0]=min(dp[i-1][1], dp[i][0]) ;
        if(s[i-1]<=r[i]) dp[i][1]=min(dp[i-1][0]+c[i], dp[i][1]) ;
        if(r[i-1]<=r[i]) dp[i][1]=min(dp[i-1][1]+c[i], dp[i][1]) ;
      }
    ans=min(dp[n-1][0], dp[n-1][1]) ;
    if(ans==INF) cout<< -1 ;
    else cout<< ans ;
  }
