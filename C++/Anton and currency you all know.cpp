#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std ;

int main()
{ int n,z=0 ;
  string s ;
  cin>> s ;
  int a[100000] ;
  n=s.length() ;
  int i ;
  for(i=0 ; i<n ; i++)
  {
     a[i] = s[i] - '0' ;
  }
  for(i=0 ; i<n ; i++)
  {  z=i ;
     if(a[i]%2==0)  break;
  }


  int m=n-1,q=0 ;
  for(i=0 ; i<n ; i++)
  {
    if(a[m]>a[i] && a[i]%2==0) { m=i ; break ;}
    if(a[n-1-i]%2==0 && q==0) q=n-1-i ;
  }
  if(m!=n-1) swap(a[m],a[n-1]) ;
  else swap(a[q],a[n-1]) ;
  for(i=0 ; i<n ; i++)
  {
     s[i] = a[i] + '0' ;
  }
  if(z==n-1) {z=-1 ; cout<< z ;}
  else cout<< s ;
  return 0;
}

  
