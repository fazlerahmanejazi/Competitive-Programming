#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std ;

int main()
{ long long int n, s, t, a[100001], m, q=0 ;
  cin>> n >> s >> t ;
  for(int i=1 ; i<=n ; i++)
  {
    cin>> a[i] ;
  }
  if(s==a[s] && s!=t) cout << "-1" ;
  else
  {
      if(s==t) cout<< "0" ;
      else
      { m=s ;
        while(1)
         { q++ ;
           s=a[s] ;
           if(t==s) { cout<< q ; break ; }
           if(m==s) { cout << "-1" ; break ; }
      }
  }
}
  return 0 ;
}
