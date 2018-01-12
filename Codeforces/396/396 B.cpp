#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int n ;
  bool check=false ;
  cin>> n ;
  vector<int> sides(n) ;
  for(int i=0 ; i<n ; i++)
    cin>> sides[i] ;
  sort(sides.begin(), sides.end()) ;
  for(int i=0 ; i+2<n ; i++)
    {
      if(sides[i]+sides[i+1]>sides[i+2])
        {
          check=true ;
          break ;
        }
    }
  if(check) cout<< "YES" ;
  else cout<< "NO" ;
  return 0;
}
