#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int n, temp, check=0 ;
  string s ;
  cin>> n ;
  for(int i=0 ; i<n ; i++)
  {
    cin>> temp >> s ;

    if(check==0 && s!="South") { cout<< "NO" ; return 0 ;}
    if(check==20000 && s!="North") { cout<< "NO" ; return 0 ;}
    if(check<0 || check>20000) { cout<< "NO" ; return 0 ;}

    if(s=="North")
     {
       check=check-temp ;
     }
    else if(s=="South")
     {
        check=check+temp ;
     }
  }
  if(check==0) cout<< "YES" ;
  else cout<< "NO" ;

  return 0 ;
}
