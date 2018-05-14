#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define PI 3.1415926535897932384626433832795
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
    int n, a, b, T, curr, ans=0, l, r, m, x, remain, first=0 ;
    string s ;
    cin>> n >> a >> b >> T ;
    cin>> s ;
    s="#"+s+s ;
    vi dp(2*n+1, 0) ;
    if(s[n+1]=='w') first=b ;
    first++ ;
    for(int i=n+2 ; i<=2*n ; i++)
      {
        if(s[i]=='w') dp[i]=b ;
        dp[i]+=dp[i-1]+a+1 ;
      }
    for(int i=n ; i>=1 ; i--)
      {
        if(s[i]=='w') dp[i]=b ;
        dp[i]+=dp[i+1]+a+1 ;
      }
    for(int i=n+1 ; i<=2*n ; i++)
      {
        l=1 ; r=n+1 ;
        remain=T-dp[i]-first ;
        if(remain<0) continue ;
        while(l<=r)
          {
            m=(l+r)/2 ;
            curr=abs(i-n-1)*a+dp[m] ;
            if(curr<=remain)
              {
                r=m-1 ;
                ans=max(ans, i-m+1) ;
              }
            else l=m+1 ;

          }
      }
    for(int i=n+1 ; i>=1 ; i--)
      {
        l=n+1 ; r=2*n ;
        remain=T-dp[i]-first ;
        if(remain<0) continue ;
        while(l<=r)
          {
            m=(l+r)/2 ;
            curr=abs(n+1-i)*a+dp[m] ;
            if(curr<=remain)
              {
                l=m+1 ;
                ans=max(ans, m-i+1) ;
              }
            else r=m-1 ;
          }
      }
    ans=min(ans, n) ;
    cout<< ans ;
  }
