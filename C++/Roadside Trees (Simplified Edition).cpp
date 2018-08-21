#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std ;

int main()
{ long long int i=0, n, h1, h2, t ;
  cin>> n ;
  cin>> h1 >> h2 ;
  t=h1 ;
  while(i<n-1)
{
  t= t + abs(h2-h1) ;
  h1=h2 ;
  cin>> h2 ;
  i++ ;
}
  t= t + 2*n - 1 ;
  cout<< t ;
  return 0 ;
}
