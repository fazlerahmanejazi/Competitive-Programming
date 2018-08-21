#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n, temp, i ;
    cin>> n ;
    vector<long long int> freq(100010, 0), dp(100010) ;
    for(i=0 ; i<n ; i++)
      {
        cin>> temp ;
        freq[temp]++ ;
      }
    dp[0]=0 ;
    dp[1]=freq[1] ;
    for(i=2 ; i<=100000 ; i++)
        dp[i]=max(dp[i-1], dp[i-2]+freq[i]*i) ;
    cout<< dp[100000] ;
  }
