#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n, k, m, z ;
    cin>> n >> k ;
    m=n/2 ;
    if(n==1 && k==0)
      {
        cout<< 1 ;
        return 0 ;
      }
    if(m>k || n==1)
      {
        cout<< -1 ;
        return 0 ;
      }
    z=k-m+1 ;
    cout<< z << " " ;
    for(int i=1 ; i<n ; i++)
      cout<< 2*z+i-1 << " " ;
  }
