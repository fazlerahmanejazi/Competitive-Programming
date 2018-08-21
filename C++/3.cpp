#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int n, curr, prev, last_score, current_score, ans=1000000, sum ;
  cin>> n ;
  cin>> last_score >> prev ;
  if(prev==2)
  {
    ans=1899+last_score ;
  }
  for(int i=1 ; i<n ; i++)
  {
    cin>> current_score >> curr ;
    if(curr==1)
    {
      if(prev==2)
      {
        if(ans<1900) { cout<< "Impossible" ; return 0 ; }
        ans=ans+current_score ;
      }
      else
      {
        ans=ans+current_score ;
      }
    }
    else
    {
      if(prev==2)
      {
        if(ans>1899) ans=1899 ;
        ans=ans+current_score ;
      }
      else
      {
        if(last_score>0) { cout<< "Impossible" ; return 0 ; }
        ans=ans+current_score ;
      }

    }
    last_score=current_score ;
    prev=curr ;

   }
   if(ans>10000) cout<< "Infinity" ;
   else cout<< ans ;

return 0 ;
}
