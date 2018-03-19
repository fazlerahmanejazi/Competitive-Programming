#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int T, n ;
    char c ;
    bool valid ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        vector<char> snake ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> c ;
            if(c!='.') snake.push_back(c) ;
          }
        if(snake.size()%2) valid=false ;
        else valid=true ;
        for(int i=0 ; i<snake.size() ; i+=2)
          if(snake[i]!='H')
            {
              valid=false ;
              break ;
            }
        for(int i=1 ; i<snake.size() ; i+=2)
          if(snake[i]!='T')
            {
              valid=false ;
              break ;
            }
        cout<< ((valid)? "Valid" : "Invalid") << endl;
      }
  }
