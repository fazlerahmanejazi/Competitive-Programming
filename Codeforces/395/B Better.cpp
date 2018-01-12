#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  long int n, temp ;
  cin>> n ;
  vector<long int> cubes(n) ;
  for(long int i=0 ; i<n ; i++)
   cin>> cubes[i] ;
  for(long int i=0 ; i<n/2 ; i=i+2) 
   {
     temp=cubes[i] ;
     cubes[i]=cubes[n-1-i] ;
     cubes[n-1-i]=temp ;
   }
   for(long int i=0 ; i<n ; i++)
     {
       if(i!=n-1) cout<< cubes[i] << " " ;
       else cout<< cubes[i] ;
     }
  return 0 ;
}
