#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std ;

int main()
{ int a[101][101],b[101][101], n, m ;
  cin>> n >> m ;
  int i, j ;
  for(i=0 ; i<n ; i++)
  {
      for(j=0 ; j<m ; j++)
      {
          cin>> a[i][j] ;
          b[i][j]=1 ;
      }
  }
  for(i=0 ; i<n ; i++)
  {   j=0 ;
      if(a[i][j]==0)
      {
      for( ; j<m ; j++)
      {
        a[i][j]=2 ;
      }
      }
  }

  for(j=0 ; i<n ; i++)
  {   i=0 ;
      if(a[i][j]==0)
      {
      for( ; i<m ; i++)
      {
        a[i][j]=2 ;
      }
      }
  }

  for(i=0 ; i<n ; i++)
  {
      for(j=0 ; j<m ; j++)
      {
          if(a[i][j]==2) a[i][j]=0 ;
      }
  }
  #include <iostream>
using namespace std;

int main()
{  int x, y ;
   int n ;
   int dx, dy;
   while(1)
  { cin>> n ;
 	if(n==0) break ;
 	cin>> dx >> dy ;
 	for(int i ; i<n ; i++)
 	 { 	cin>> x >> y ;
 		if(x==dx || y==dy) cout<< "divisa" ;
 		if(x>dx) { if(y>dy) cout<< "NE" ;
 		           else cout<< "SE" ; }
		else {     if(y<dy) cout<< "SO" ;
 		           else cout<< "NO" ; }
   } }   return 0; }
