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
    lli x=1, prev=0 ;
    vlli a ;
    a.pb(0) ;
    for(int i=1 ; i<=200 ; i++)
      {
        a.pb(prev+x) ;
        x++ ;
        prev=a[i] ;
      }
    for(int tc=1 ; tc<=T ; tc++)
      {
        lli r, b, dp[510][510], ans ;
        cin>> r >> b ;
        memset(dp, 0, sizeof dp) ;
        for(int i=0 ; i<=max(r, b) ; i++)
          {
            x=upper_bound(all(a), i)-a.begin() ;
            dp[i][0]=dp[0][i]=x-1 ;
          }
        for(int i=1 ; i<=r ; i++)
          for(int j=1 ; j<=b ; j++)
            {
              x=upper_bound(all(a), i)-a.begin() ;

            }
        cout<< "Case #" << tc << ": " << ans << endl ;
      }
  }
