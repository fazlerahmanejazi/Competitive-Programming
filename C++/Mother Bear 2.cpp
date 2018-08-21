#include <bits/stdc++.h>
using namespace std ;
int main()
{ char s[100] ;
  int f=1, j=0 ;
  cin.getline(s,100) ;
  char r[100] ;
  for(int i=0 ; i<strlen(s) ; i++)
  { s[i]=tolower(s[i]) ;
    if(s[i]>='a' && s[i]<='z') { r[j]=s[i] ; j++ ; }
  }
  int k=j-1 ;
  for( int i=0; i<j ; i++)
  {
    if(r[i]!=r[k]) f=0 ;
    k-- ;
  }
  if(f!=0) cout<< "You won’t be eaten!" ;
  else cout<< "Uh oh.." ;
  return 0 ;
}
