#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    string s, a ;
    cin>> s ;
    int l=s.length() ;
    for(int i=0 ; i<l ; i++)
      if(i+2<l && s[i]==s[i+1] && s[i+1]==s[i+2])
        s[i]='0' ;
    for(int i=0 ; i<l ; i++)
      if(s[i]!='0') a+=s[i] ;
    s=a ;
    l=s.length() ;
    for(int i=0 ; i<l ; )
      if(i+3<l && s[i]==s[i+1] && s[i+2]==s[i+3])
        {
          s[i+2]='0' ;
          i=i+3 ;
        }
      else i++ ;
    for(int i=0 ; i<l ; i++)
      if(s[i]!='0') cout<< s[i] ;
  }
