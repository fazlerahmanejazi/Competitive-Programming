#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n, k, d, a, b ;
    cin>> n >> k >> d ;
    vector<long long int> dp(n+1, 0) ;
    for(int i=1 ; i<=min(n,k) ; i++)
      dp[i]=1 ;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=min(k,i) ; j++)
            dp[i]=(dp[i]+dp[i-j])%1000000007 ;
    a=dp[n]%1000000007 ;
    dp.assign(n+1, 0) ;
    for(int i=1 ; i<=min({n,k,d-1}) ; i++)
      dp[i]=1 ;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=min({k,i,d-1}) ; j++)
            dp[i]=(dp[i]+dp[i-j])%1000000007 ;
    b=dp[n]%1000000007 ;
    cout<< (a-b+1000000007)%1000000007 ;
  }
