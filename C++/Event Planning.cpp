#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std ;

int main()
{   int n, h, w, a[18][13] ;
    long long int b, p[18], c[18] ;
    while(cin>> n >> b >> h >> w)         /* Here the concept of EOF has been used. Since the number of test cases are not specified,
                                          we are using this. This will conitnue until the user stops giving the input*/
  {
    for(int i=0 ; i<h ; i++)
    { cin>>p[i] ;
      for(int j=0 ; j<w ; j++)
         {  cin>> a[i][j] ;
            if(a[i][j]>=n) c[i]=n*p[i] ;
         }
    }
    sort(c,c+h) ;
    if(c[0]<=b) cout<< c[0] << endl ;
    else cout<< "stay home" << endl ;
  }
    return 0;
}
