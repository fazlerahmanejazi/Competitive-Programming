#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int T, n, x, A, B, a, b ;
  cin>> T ;
  while(T--)
    {
      cin>> n ;
      A=0 ; B=0 ; a=0 ; b=0 ;
      for(int i=1 ; i<=n ; i++)
        {
          cin>> x ;
          if(i%2==0) A+=x ;
          else B+=x ;
        }
      for(int i=1 ; i<=n ; i++)
        {
          cin>> x ;
          if(i%2==0) a+=x ;
          else b+=x ;
        }
      cout<< min(A+b, a+B) << endl ;
    }
  return 0 ;
}
