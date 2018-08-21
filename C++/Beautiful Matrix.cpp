#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;


int main()
{ const int m=5 ;
  int a[m][m] ;
  for(int i=0 ; i<m ; i++)
  { for(int j=0 ; j<m ; j++)
    {cin>> a[i][j] ;}
  }
  
  int x,y ;
  
  for(int i=0 ; i<m ; i++)
  { for(int j=0 ; j<m ; j++)
    {if(a[i][j]==1) 
    { x=i+1 ; y=j+1 ;}
    }
  }
  
  x=abs(x-3);
  y=abs(y-3);
  
  cout<< x+y ;
  
  return 0;
   
}
