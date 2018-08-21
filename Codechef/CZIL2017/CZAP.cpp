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

lli n, q, x, l, r, d, a[100005], dp[100005][305] ;

void preprocess()
  {
    memset(dp, 0, sizeof dp) ;
    for(int i=1 ; i<=300 ; i++)
      {
        for(int j=1 ; j<=i ; j++) dp[j][i]=a[j] ;
        for(int j=i+1 ; j<=n ; j++) dp[j][i]=dp[j-i][i]+a[j] ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    preprocess() ;
    cin>> q ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> l >> r >> d ;
        l++ ; r++ ;
        if(d<=300)
          {
            r=l+d*((r-l)/d) ;
            l=max(l-d, 0LL) ;
            cout<< dp[r][d]-dp[l][d] << endl ;
          }
        else
          {
            x=0 ;
            while(l<=r) x+=a[l], l+=d ;
            cout<< x << endl ;
          }
      }
  }
