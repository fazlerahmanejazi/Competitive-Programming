#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int T, c ;
  string s ;
  cin>> T ;
  while(T--)
    {
      set<string> recipe ;
      set<string>::iterator it ;
      c=0 ;
      for(int i=0 ; i<4 ; i++)
        {
          cin>> s ;
          recipe.insert(s) ;
        }
      for(int i=0 ; i<4 ; i++)
        {
          cin>> s ;
          it=recipe.find(s) ;
          if(it!=recipe.end()) c++ ;
        }
      if(c>=2) cout<< "similar" << endl ;
      else cout<< "dissimilar" << endl ;
    }
  }
