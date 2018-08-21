#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std ;

int main()
{ long long int r,x,y,X,Y ;
  long double d ;
  cin>> r >> x >> y >> X >> Y ;
  d=sqrt((x-X)*(x-X) + (y-Y)*(y-Y)) ;
  long long int D ;
  if(d==floor(d)) {D=d ; if(D%(2*r)==0) cout << (D/(2*r)) ; else cout<< floor((D/(2*r))) + 1 ;}
  else { 
          D=floor(d) ;
          r=floor((D/(2*r))) + 1 ; cout << r ;} 
  return 0 ;
}
  
