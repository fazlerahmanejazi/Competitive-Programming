#include <bits/stdc++.h>
using namespace std ;

long int gcd ( long int a, long int b )
{
  long int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
int main()
{
  long int a, b,temp ;
  cin>> a >> b ;
  temp= gcd(a,b) ;
  temp=(a*b)/temp ;
  cout<< temp ;
  return 0 ;
}
