int fuction(vector<int> arr)
  {
    sort(arr.begin(), arr.end()) ;
    int n=arr.size(), ans=arr[0], last=arr[0] ;
    for(int i=1 ; i<n ; i++)
      if(arr[i]>last) ans+=arr[i], last=arr[i] ;
      else ans+=(++last) ;
    return ans ;
  }


int shortestPalindrome(string s)
  {
    int n=s.size() ;
    int dp[n+1][n+1], l, r ;
    memset(dp, 0, sizeof dp) ;
    for(int sz=1 ; sz<n ; sz++ )
      for(int i=0, j=sz ; j<n ; i++, j++)
        if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]
        else dp[i][j]=min(dp[i][j-1], dp[i+1][j])+1 ;
    return dp[0][n-1] ;
  }
