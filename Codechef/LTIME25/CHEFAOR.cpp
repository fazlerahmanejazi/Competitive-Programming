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

lli T, n, k, a[5005], dp[5005][5005], cost[5005][5005] ;

void init()
  {
    memset(cost, 0, sizeof cost) ;
    memset(dp, 0, sizeof dp) ;
  }

void compute(lli j, lli L, lli R, lli optL, lli optR)
  {
    if(R<L) return ;
    lli m=(L+R)/2, best=optL, curr ;
    dp[m][j]=0 ;
    for(int k=optL ; k<=min(m, optR) ; k++)
      {
        curr=dp[k][j-1]+cost[k+1][m] ;
        if(curr>dp[m][j]) dp[m][j]=curr, best=k ;
      }
    compute(j, L, m-1, optL, best) ;
    compute(j, m+1, R, best, optR) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        init() ;
        cin>> n >> k ;
        for(int i=1 ; i<=n ; i++) cin>> a[i] ;
        for(int i=1 ; i<=n ; i++)
          for(int j=i ; j<=n ; j++)
            cost[i][j]|=(a[j]|cost[i][j-1]) ;
        for(int j=1 ; j<=k ; j++) compute(j, 1, n, 0, n) ;
        cout<< dp[n][k] << endl ;
      }
  }
