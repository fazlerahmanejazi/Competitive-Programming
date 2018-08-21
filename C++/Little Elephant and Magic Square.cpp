#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std ;

int main()
{ long long int a[3][3], x,y=0;
  for(int i=0 ; i<3 ; i++)
  {
    for(int j=0 ; j<3 ; j++)
    {
      cin>>a[i][j] ;
      if(a[i][j]>y) y=a[i][j] ;
    }
  }
  x=a[0][2]+a[2][0] ;
  for(int i=0 ; i<=x ; i++)
  {
    a[0][0]=i ; a[2][2]=x-i ;
    if((a[0][0]+a[0][1]+a[0][2])==(a[2][0]+a[2][1]+a[2][2])
    && (a[0][0]+a[0][1]+a[0][2])==(a[0][0]+a[1][0]+a[2][0])
    && (a[0][0]+a[0][1]+a[0][2])==(a[0][2]+a[1][2]+a[2][2]))
    break ;
  }
  for(int i=0 ; i<=y ; i++)
  { a[1][1]= i ;
    if((a[0][0]+a[1][1]+a[2][2])==(a[0][0]+a[0][1]+a[0][2])) break ;
  }
  for(int i=0 ; i<3 ; i++)
  {
    for(int j=0 ; j<3 ; j++)
    {
      cout<<a[i][j] << " " ;
    }
    cout<< endl ;
  }
  return 0 ;
}
