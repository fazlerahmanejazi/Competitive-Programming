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
    int n ;
    cin>> n ;
    n-=2 ;
    long double dp[500][500], ans=0 ;
    memset(dp, 0, sizeof dp) ;
    for(int i=1 ; i<=400 ; i++) dp[0][i]=dp[1][i]=1 ;
    for(int i=2 ; i<=n ; i++)
      for(int t=2 ; t<=n ; t++)
        if(t<i) for(int j=1 ; j<=i ; j++) dp[i][t]+=(1/((long double)i))*(dp[i-j][t-1]*dp[j-1][t-1]) ;
        else dp[i][t]=1 ;
    for(int i=1 ; i<=n ; i++) ans+=i*(dp[n][i]-dp[n][i-1]) ;
    cout<< fixed << setprecision(12) << 10*ans ;
  }
