#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std ;

int main()
{ string s ;
  int k ;
  cin>> s ;
  cin>> k ;
  int n=s.length() ;
  int w[26], max=0,x,sum=0;
  for(int i=0 ; i<26 ; i++)
  {
    cin>> w[i] ;
    if(w[i]>max) max=w[i] ;
  }

  for(int i=0 ; i<n ; i++)
  { x=s[i]-'a' ;
    sum=sum+((i+1)*w[x]) ;
  }
  //for(int i=1 ; i<=k; i++)
  //{ sum=sum+(n+i)*max ;
  //}
  int l= (k*(2*n + 1 + k))/2 ;
  sum=sum+max*l ;
  cout<< sum ;
  return 0;
}
