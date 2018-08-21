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
    lli n, m, ans, curr ;
    cin>> n >> m ;
    vlli a(n+2), dp1(n+2), dp2(n+2) ;
    for(int i=1 ; i<=n ; i++ ) cin>> a[i] ;
    a[n+1]=m ;
    dp1[0]=a[1] ;
    for(int i=1 ; i<=n ; i++)
      if(i%2) dp1[i]=dp1[i-1], dp2[i]=dp2[i-1]+a[i+1]-a[i] ;
      else dp2[i]=dp2[i-1], dp1[i]=dp1[i-1]+a[i+1]-a[i] ;
    ans=dp1[n] ;
    for(int i=0 ; i<=n ; i++)
      if(a[i+1]!=a[i]+1)
        {
          if(i%2) ans=max(ans, dp1[i-1]+a[i+1]-a[i]-1+dp2[n]-dp2[i]) ;
          else
            {
              if(i) curr=dp1[i-1] ;
              else curr=0 ;
              ans=max(ans, curr+a[i+1]-a[i]-1+dp2[n]-dp2[i]) ;
            }
        }
    cout<< ans ;
  }
