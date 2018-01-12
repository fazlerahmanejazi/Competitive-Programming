#include <bits/stdc++.h>
using namespace std ;

int main()
 {
  ios_base::sync_with_stdio (false) ; cin.tie(0) ;
  int T, c, l, k ;
  long long int ans ;
  string s ;
  cin>> T ;
  while(T--)
    {
      cin>> s ;
      c=ans=0 ;
      l=s.length() ;
      k=l-1 ;
      for(int i=0 ; i<l ; i++)
        if(s[i]=='1') c++ ;
        else if(i>0 && s[i-1]=='1') ans+=c ;
      for(int i=l-1 ; i>=0 ; i--)
        if(s[i]=='1')
            ans+=(k---i) ;
      cout<< ans << endl ;
    }
  }
