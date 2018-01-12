#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int T, n, m, k, curr, maxm ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> m >> k ;
        vector<vector<int > > a(n+10, vector<int>(m+10)) ;
        for(int i=0 ; i<n ; i++)
          for(int j=0 ; j<m ; j++)
            cin>> a[i][j] ;
        curr=0 ; maxm=-1 ;
        for(int i=0 ; i<n ; i++)
          {
            curr=0 ;
            for(int j=0 ; j<m ; j++)
              {
                if(a[i][j]=0)
                  {
                    maxm=max(maxm, curr) ;
                    curr=0 ;
                  }
                else
                  {
                    curr++ ;
                    maxm=max(maxm, curr) ;
                    if(i-1>=0)
                      {
                        if(a[i-1][j]!=0)
                          {
                            a[i][j]=(a[i-1][j]+1)%k ;
                            curr=(a[i][j]+1)%k ;
                          }
                        else
                          {
                            a[i][j]=curr ;
                          }
                      }
                    else
                      a[i][j]=curr ;
                  }
              }
          }
        for(int i=0 ; i<m ; i++)
          {
            curr=0 ;
            for(int j=0 ; j<n ; j++)
              {
                if(a[j][i]=0)
                  {
                    maxm=max(maxm, curr) ;
                    curr=0 ;
                  }
                else
                  {
                    curr++ ;
                    maxm=max(maxm, curr) ;
                  }
              }
          }
        for(int i=0 ; i<n ; i++)
          {
            for(int j=0 ; j<m ; j++)
              cout<< a[i][j] << " " ;
            cout<< endl ;
          }
      }
    }
