#include <bits/stdc++.h>
using namespace std ;

string s ;
int l, res ;
int main()
  {
    cin>> s ;
    l=s.length() ;
    for(auto c:s)
      {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') res=res+1 ;
        if(c<'a' || c>'z')
          {
            int x=c-'0' ;
            res=res+(x%2) ;
          }
      }
    cout<< res ;
  }
