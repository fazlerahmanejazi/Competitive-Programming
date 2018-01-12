#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  long long int n, count=0, total=0, ans=0 ;
  cin>> n ;
  long long int num[n], sum[n] ;
  for(int i=0 ; i<n ; i++)
    {
      cin>> num[i] ;
      if(i==0) sum[0]=num[0] ;
      else sum[i]=sum[i-1]+num[i] ;
    }
  if(sum[n-1]%3!=0) { cout<< 0 ; return 0 ;}
  total=sum[n-1]/3 ;
  for(int i=0 ; i<n-1 ; i++)
  {
  	if(sum[i]==2*total) ans=ans+count ;
    if(sum[i]==total) count++ ;
  }
  cout<< ans ;
  return 0;
}
