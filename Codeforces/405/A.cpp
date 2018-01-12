#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int a, b, t=1 ;
  cin>> a >> b ;
  while(t++)
    {
      a=a*3 ;
      b=b*2 ;
      if(a>b)
        {
          cout<< t-1 ;
          return 0 ;
        }
    }
}
