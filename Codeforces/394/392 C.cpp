#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int n, m, ans=10000, temp, index ;
  cin>> n >> m ;
  string a ;
  int digit[n], lower[n], symbols[n] ;
  memset(digit, 10000, sizeof digit) ;
  memset(lower, 10000, sizeof lower) ;
  memset(symbols, 10000, sizeof symbols) ;

  for(int i=0 ; i<n ; i++)
   {
     cin>> a ;

     for(int j=0 ; j<a.length() ; j++)
     {
       if(a[j]>='0' && a[j]<='9') digit[i]=min(digit[i], min(j, m-j)) ;
     }

     for(int j=0 ; j<a.length() ; j++)
     {
       if(a[j]>='a' && a[j]<='z') lower[i]=min(lower[i], min(j, m-j)) ;
     }

     for(int j=0 ; j<a.length() ; j++)
     {
       if(a[j]=='#' || a[j]=='&' || a[j]=='*') symbols[i]=min(symbols[i], min(j, m-j)) ;
     }

   }
  for(int i=0 ; i<n ; i++)
  {
    for(int j=0 ; j<n ; j++)
    {
    	if(i==j) continue;
      for(int k=0 ; k<n  ; k++)
      {
      	if(k==i) continue;
		if(k==j) continue;
        ans=min(ans, digit[i]+lower[j]+symbols[k]) ;
      }
    }
  }

   cout<< ans ;
  return 0 ;
}
