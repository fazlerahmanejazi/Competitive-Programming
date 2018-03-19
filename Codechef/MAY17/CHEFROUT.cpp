#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    int n ;
    string s ;
    bool check ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> s ;
        check=true ;
        for(int i=0 ; i<s.length()-1 ; i++)
          if(s[i]>s[i+1])
            {
              check=false ;
              break ;
            }
        if(check) cout<< "yes" << endl ;
        else cout<< "no" << endl ;
      }
  }
