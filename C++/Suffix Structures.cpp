#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std ;

int main()
{ string s, t ;
  cin>> s >> t ;
  int ls=s.length(), lt=t.length() ;
  if(ls<lt) cout<< "need tree" ;
  else
  {
    if(ls==lt)
    { lt=0 ;
      sort(s.begin(),s.end()) ; sort(t.begin(),t.end()) ;
      for(int i=0 ; i<ls ; i++)
      {
          if(s[i]==t[i]) lt++ ;
      }
      if(lt==ls) cout<< "array" ;
      else cout<< "need tree" ;
    }
    else
    { int x=0,y=0,i=0 ;
      for(i=0 ; i<lt ; i++)
      {
        for(int j=x ; j<ls ; j++)
        {
          if(t[i]==s[j]) { x=j+1 ;y++ ; break ; }
        }
      }

      if(y==lt) cout<< "automaton" ;
      else
       {  sort(s.begin(),s.end()) ; sort(t.begin(),t.end()) ;
          int x=0,y=0,i=0 ;
          for(i=0 ; i<lt ; i++)
        {
          for(int j=x ; j<ls ; j++)
        {
          if(t[i]==s[j]) { x=j+1 ;y++ ; break ; }
        }
        }
          if(y==lt) cout<< "both" ;
          else cout<< "need tree" ;
       }
    }
  }
  return 0 ;
}
