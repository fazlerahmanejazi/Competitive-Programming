#include <iostream>
#include <cmath>
using namespace std ;

int main()
{ long int n ;
  long long int x[100000] ;
  cin>> n ;
  for(int i=0 ; i<n ; i++)
  {
    cin>> x[i] ;
  }
  long long int a,z ;

  for(int i=0 ; i<n ; i++)
  { z=0 ;
    a=pow(x[i],1/2.) ;
    for(int j=1 ; i<=pow(a,1/2.) ; i++)
    {
      if(a%j==0) z++ ;
    }
    if(z==0) {cout<< "YES" << endl ;}
    else {cout<< "NO" << endl ; }
  }
  return 0 ;
}
