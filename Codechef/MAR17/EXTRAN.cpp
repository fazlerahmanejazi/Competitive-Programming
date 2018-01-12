#include <bits/stdc++.h>
using namespace std ;

#define inf 1000000000

int main()
{
  ios_base::sync_with_stdio (false) ;
  int T, n, x, ans ;
  cin>> T ;
  while(T--)
    {
      cin>> n ;
      map<int, bool> occur ;
      int l=inf, u=-inf ;
      bool repeat=false ;
      for(int i=0 ; i<n ; i++)
        {
          cin>> x ;
          if(!occur[x]) occur[x]= true ;
          else { repeat=true ; ans=x ; }
          l=min(x,l) ;
          u=max(x,u) ;
        }
      if(repeat) cout<< ans << endl ;
      else
        {
          if(!occur[l+1]) cout<< l << endl ;
          else cout<< u << endl ;
        }
    }
  return 0 ;
}
