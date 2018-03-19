#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    bool check ;
    int l=0 ;
    string s, r="bba" ;
    cin>> s ;
    int c=0 ;
    while(1)
      {
        check=true ;
        for(int i=l ; i<s.length()-1 ; i++)
          {
            if(s[i]=='a' && s[i+1]=='b')
              {
                s[i]='b' ;
                s.insert(i+2, "a") ;
                c++ ;
                l
                check=false ;
              }
          }
        if(check) break ;
      }
    cout<< c ;
  }
