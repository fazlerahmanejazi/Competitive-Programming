#include <bits/stdc++.h>
using namespace std ;


int main()
{
  ios_base::sync_with_stdio (false) ;
  int n, m=-1, sum=0 ;
  cin>> n ;
  vector<int> a(n) ;
  for(int i=0 ; i<n ; i++)
  {
    cin>> a[i] ;
    if(a[i]>m) m=a[i] ;
  }
  for(int i=0 ; i<n ; i++)
    sum=sum+ (m-a[i]) ;
  cout<< sum ;
  return 0 ;
}
  
