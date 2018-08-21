#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int n, k ;
  cin>> n >> k ;
  int c=1, r, temp ;
  r=240 - k ;
  temp=(5*c*(c+1))/2 ;
  while(temp<=r)
  {
    c++ ;
    temp=(5*c*(c+1))/2 ;
    if(c>n) break ;
  }
  cout<< c-1 ;
  return 0 ;
}
  
