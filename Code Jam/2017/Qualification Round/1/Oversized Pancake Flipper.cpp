#include <bits/stdc++.h>
using namespace std ;

int T, k, l, ans ;
string s ;
bool possible ;

bool check()
  {
    for(int i=0 ; i<l ; i++)
        if(s[i]=='-')
          return false ;
    return true ;
  }

void flip(int pos)
  {
    for(int i=pos ; i<pos+k ; i++)
      {
        if(s[i]=='-') s[i]='+' ;
        else s[i]='-' ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> s >> k ;
        l=s.length() ;
        ans=0 ;
        possible=false ;
        if(check()) possible=true ;
        else
          {
            for(int i=0 ; i<=l-k ; i++)
              {
                if(s[i]=='-')
                  {
                    flip(i) ;
                    ans++ ;
                    if(check())
                      {
                        possible=true ;
                        break ;
                      }
                  }
              }
          }
        if(possible) cout<< "Case #" << tc << ": " << ans << endl ;
        else cout<< "Case #" << tc << ": IMPOSSIBLE" << endl ;
      }
  }
