


/* This program gives wrong output. The main difference is using "string s;" " datatype and "char s[100]. In former we
use strlen() and in latter we use .length(). Both give diffrent outputs."*/



#include <bits/stdc++.h>
using namespace std ;
int main()
{ string s ;
  int f=1, j=0 ;
  cin>> s ;
  s=tolower(s) ;
  char r[100] ;
  for(int i=0 ; i<s.length() ; i++)
  {
    if(s[i]>='a' && s[i]<='z') { r[j]=s[i] ; j++ ; }
  }
  for( int i=0,k=j-1 ; i<j,k>=0 ; i++,k--)
  {
    if(r[i]!=r[j]) f=0 ;
  }
  if(f!=0) cout<< "You won’t be eaten!" ;
  else cout<< "Uh oh.." ;
  return 0 ;
}
