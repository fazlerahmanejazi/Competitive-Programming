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

int n, S, dp[101][100001], taken[101] ;
vi a ;

void reconstruct(int n, int s)
  {
    if(n<=0) return ;
    if(dp[n][s]==dp[n-1][s]) reconstruct(n-1, s) ;
    else taken[n]=true, reconstruct(n-1, s-a[n]) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> S >> n ;
    a.resize(n+2) ;
    for(int i=0 ; i<=n ; i++) dp[i][0]=1 ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=S ; j++)
        {
          dp[i][j]=dp[i-1][j] ;
          if(a[i]<=j) dp[i][j]+=dp[i-1][j-a[i]] ;
        }
    if(!dp[n][S]) cout<< 0 ;
    else if(dp[n][S]==1)
      {
        reconstruct(n, S) ;
        for(int i=1 ; i<=n ; i++) if(!taken[i]) cout<< i << " " ;
      }
    else cout<< -1 ;
  }
