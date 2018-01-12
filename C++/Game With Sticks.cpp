#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;


int main()
{ int m, n ;
  cin>> m >> n ;
  int i=0 ;
  int a=m*n ;
  while(a!=0)
  {
  	a=a-m-n+1 ;
  	m=m-1 ;
  	n=n-1 ;
  	i=i+1 ;
  }
  
  if(i%2==0) cout<< "Malvika" ;
  else cout<< "Akshat" ;
  
  return 0 ;
  
}
