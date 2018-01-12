#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;


int main()
{ int n ;
  int h[101], g[101] ;
  cin>> n ;
  int a=0 ;
  
  for(int i=0 ; i<n ; i++)
  { cin>> h[i] >> g[i] ; }

  for(int i=0 ; i<n ; i++)
  {  for(int j=0 ; j<n ; j++)
     { if(h[j]==g[i]) a=a+1 ;}
  }

  cout<< a ;

  return 0 ;
  }

    
