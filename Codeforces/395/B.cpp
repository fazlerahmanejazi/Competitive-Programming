#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  long int n, l, u ;
  cin>> n ;
  vector<long int> cubes(n) ;
  for(long int i=0 ; i<n ; i++)
   cin>> cubes[i] ;
  if(n%2==1)
   {
     l=n/2 ;
     u=n/2 ;
   }
  else
   {
     u=n/2 ;
     l=u-1 ;
   }
   while(l>=0)
    {
      reverse(cubes.begin()+l, cubes.begin()+u+1) ;
      l-- ;
      u++ ;
    }
   for(long int i=0 ; i<n ; i++)
     {
       if(i!=n-1) cout<< cubes[i] << " " ;
       else cout<< cubes[i] ;
     }
  return 0 ;
}

  
