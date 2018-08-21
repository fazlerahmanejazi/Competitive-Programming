#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int l, n, check=0, temp ;
  cin>> n >> l ;
  vector<int> a(n) , b(n), dA(n), dB(n) ;
  cin>> temp ;
  a[0]=0 ;
  for(int i=1 ; i<n ; i++)
  {
    cin>> a[i] ;
    a[i]=a[i]-temp ;
  }
  cin>> temp ;
  b[0]=0 ;
  for(int i=1 ; i<n ; i++)
  {
    cin>> b[i] ;
    b[i]=b[i]-temp ;
  }
  for(int i=0 ; i<n-1 ; i++)
  {
    dA[i]=a[i+1]-a[i] ;
    dB[i]=b[i+1]-b[i] ;
  }
  dA[n-1]=l-a[n-1] ;
  dB[n-1]=l-b[n-1] ;

  for(int i=0 ; i<=n ; i++)
  {
    if(dA==dB) { check=1 ; break ; }
    else
    {
      temp=dA[n-1] ;
      dA.pop_back() ;
      dA.insert(dA.begin(), temp) ;
    }
  }
  if(check) cout<< "YES" ;
  else cout<< "NO" ;
  return 0 ;
}
