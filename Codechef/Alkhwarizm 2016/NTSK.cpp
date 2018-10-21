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

lli n, m, q, x, ans, dp[110][110], a[110] ;

void fillDP()
  {
    for(int i=1 ; i<=101 ; i++)
      for(int j=1 ; j<=101 ; j++)
        dp[i][j]=-INF ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=n ; j++)
        {
          lli curr=-INF, mx=-INF ;
          for(int k=i ; k>=j ; k--)
            {
              curr=max(a[k], a[k]+curr) ;
              mx=max(mx, curr) ;
              dp[i][j]=max(dp[k-1][j-1]+mx, dp[i][j]) ;
            }
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    fillDP() ;
    cin>> q ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> x ;
        ans=-1 ;
        for(int j=1 ; j<=n ; j++)
          if(dp[n][j]>=x)
            {
              ans=j ;
              break ;
            }
        if(ans==-1) cout<< "Not Possible" << endl ;
        else cout<< ans << endl ;
      }
  }
