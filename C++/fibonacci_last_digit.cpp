#include <bits/stdc++.h>
using namespace std ;
int main()
  {
    long long int n, a, b, temp, k=1 ;
    cin>> n ;
    if(n==0) temp=0 ;
    else if(n==1) temp=1 ;
    else
    {   a=0, b=1 ;
      for(int i=2 ; i<=n ; i++)
       {
            temp=(a+b)%10 ;
            a=b ;
            b=temp ;
       }
    }
    cout<< temp << endl ;
  return 0 ;
  }
