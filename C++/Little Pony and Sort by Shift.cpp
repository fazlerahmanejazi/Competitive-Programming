#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std ;

int main()
{ long long int a[100000], n ;
  cin>> n ;
  long long int x=0, y=0 ;
  for(int i=0 ; i<n ; i++)
  {
    cin>> a[i] ;
  }
  for(int i=0 ; i<n-1 ; i++)
  {
    if(a[i+1]<a[i]) { x=i+1 ; y++ ; }
  }
  if(y==0) cout<< "0" ;
  else { if(y==1 && a[n-1]<=a[0]) cout<<n-x ;
	      else cout<<-1 ;

  }
  return 0 ;
}
  
