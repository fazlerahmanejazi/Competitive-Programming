#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
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

int n, a, b, k, x ;
lli dp[5000+5][5000+5], pre[5000+5] ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> a >> b >> k ;
    memset(dp, 0, sizeof dp) ;
    memset(pre, 0, sizeof pre) ;
    if(a>b)
      {
        a=n-a+1 ;
        b=n-b+1 ;
      }
    for(int i=1 ; i<=b ; i++)
      {
        if(abs(i-a)<abs(b-a) && i!=a)
          dp[i][1]=1 ;
        pre[i]=pre[i-1]+dp[i][1] ;
      }
    for(int i=2 ; i<=k ; i++)
      {
        for(int j=1 ; j<b ; j++)
          {
            x=(b+j-1)/2 ;
            dp[j][i]=(pre[x]-dp[j][i-1]+mod)%mod ;
          }
        for(int j=1 ; j<b ; j++)
          pre[j]=(pre[j-1]+dp[j][i])%mod ;
      }
    lli ans=0 ;
    for(int i=1 ; i<b ; i++)
      ans=(ans+dp[i][k])%mod ;
    cout<< ans ;
  }
