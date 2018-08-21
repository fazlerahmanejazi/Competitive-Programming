#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;


int main()
{ int t ;
  cin>> t ;
  int a[t] , b[t] ;
  char c[t] ;
  for(int i=0 ; i<t ;  i++)
  {
  	cin>> a[i] >> b[i] ;
  	if(a[i]>b[i]) c[i]='>' ;
  	if(a[i]<b[i]) c[i]='<' ;
  	if(a[i]==b[i]) c[i]='=' ;
  }
  
  for(int i=0 ; i<t ; i++)
  {
  	cout<< c[i] << endl ;
  }
 
 return 0 ;
 
}
