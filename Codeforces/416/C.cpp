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
    int n, L, R, curr ;
    cin>> n ;
    vi a(n+1), l(5010, 0), r(5010, 0), dp(n+1, 0) ;
    vb taken ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=1 ; i<=n ; i++) if(!l[a[i]]) l[a[i]]=i ;
    for(int i=n ; i>=1 ; i--) if(!r[a[i]]) r[a[i]]=i ;
    for(int i=1 ; i<=n ; i++)
      {
        L=R=i ;
        curr=0 ;
        dp[i]=dp[i-1] ;
        taken.assign(5010, false) ;
        for(int j=i ; j>=1 ; j--)
          {
            L=min(L, l[a[j]]) ;
            R=max(R, r[a[j]]) ;
            if(!taken[a[j]]) curr^=a[j], taken[a[j]]=true ;
            if(j<=L && R<=i) dp[i]=max(dp[i], curr+dp[j-1]) ;
          }
      }
    cout<< dp[n] ;
  }
