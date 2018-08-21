#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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
    string s1, s2 ;
    cin>> s1 >> s2 ;
    vi a ;
    int idx=0 ;
    while(idx<n)
      {
        if(s1[idx]!=s2[idx])
          {
            a.pb(2) ;
            idx+=2 ;
          }
        else
          {
            a.pb(1) ;
            idx++ ;
          }
      }
    vlli dp(60, 1) ;
    if(a[0]==1) dp[0]=3 ;
    else dp[0]=6 ;
    for(int i=1 ; i<a.size() ; i++)
      {
        if(a[i]==1)
          {
            if(a[i-1]==1)
              {
                dp[i]=2*dp[i-1] ;
                dp[i]=dp[i]%mod ;
              }
            else dp[i]=dp[i-1] ;
          }
        else
          {
            if(a[i-1]==1)
              {
                dp[i]=2*dp[i-1] ;
                dp[i]=dp[i]%mod ;
              }
            else
              {
                dp[i]=3*dp[i-1] ;
                dp[i]=dp[i]%mod ;
              }
          }
      }
    cout<< dp[a.size()-1] ;
  }
