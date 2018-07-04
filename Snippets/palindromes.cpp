bool isPal[n+1][n+1] ;
memset(isPal, false, sizeof isPal) ;

void build()
  {
    for(int i=1 ; i<=n ; i++) isPal[i][i]=true ;
    for(int len=2 ; len<=n ; len++)
      for(int i=1 ; i+len-1<=n ; i++)
        {
          l=i ; r=i+len-1 ;
          if(len==2) isPal[l][r]=(s[l]==s[r]) ;
          else isPal[l][r]=((s[l]==s[r])&&isPal[l+1][r-1]) ;
        }
  }
