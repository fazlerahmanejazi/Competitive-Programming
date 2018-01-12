#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  long int n, m, v=1, k=0, temp ;
  cin>> n >> m ;
  if(n>m+1 || 2*n+2<m) { cout<< -1 ; return 0 ;}
  while( n || m)
  {
    if(v==0 || (k<2 && m>n))
    {
      v=1 ;
      m-- ;
      k++ ;
    }
    else
    {
      n-- ;
      v=0 ;
      k=0 ;
    }
    cout<< v+0 ;
  }

  return 0 ;
}
