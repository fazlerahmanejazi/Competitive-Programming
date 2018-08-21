#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  string s ;
  char temp ;
  int min=100000 ;
  map<char, int> n ;
  cin>> s ;
  for(int i=0 ; i<s.length() ; i++)
    n[s[i]]++ ;
  s="Bulbasaur" ;
  n[a]=n[a]/2 ;
  n[u]=n[u]/2 ;
  for(int i=0 ; i<s.length() ; i++)
    if(n[s[i]]<=min) { min=n[s[i]] ; }
  cout<< min ;
  return 0 ;
}
