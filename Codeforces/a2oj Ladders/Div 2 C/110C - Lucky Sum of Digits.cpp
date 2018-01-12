#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, four, seven ;
    cin>> n ;
    four=(n/4)+1 ;
    seven=(n/7)+1 ;
    for(int i=0, j=seven ; i<=four ; i++)
      {
        while(4*i+7*j>n && j>0) j-- ;
        if(4*i+7*j==n)
          {
            for(int k=0 ; k<i ; k++) cout<< 4 ;
            for(int k=0 ; k<j ; k++) cout<< 7 ;
            return 0 ;
          }
      }
    cout<< -1 ;
  }
