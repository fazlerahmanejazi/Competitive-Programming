#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;


int main()
{ int n, m, max, min, a, b ;
  cin>> n >> m ;
  
  a= (n-m-1) ;
  cout<< (a*(a-1))/2 ;
  
  if(n%m==0)
  {
  a=n/m ;
  b=(a*(a-1))/2  ;
  min=a*b ;
  }
  
  else
  {
   a=m/m ;
   a=a-(n%m) ;
   
  }
 
}
