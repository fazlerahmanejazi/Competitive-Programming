#include <bits/stdc++.h>
using namespace std ;

#define mod 1000000007

long long int fast_exp(long long int base, long long int exp)
  {
      long long int z ;
      if(exp==0) return 1 ;
      if(exp==1) return base;
      if(exp%2==0)
        {
          z=pow(fast_exp(base, exp/2),2) ;
          z=z%mod ;
          return z ;
        }
      else
        {
          z=(base*pow(fast_exp(base,(exp-1)/2),2)) ;
          z=z%mod ;
          return z ;
        }
  }

int main()
  {
    int T ;
    long long int n, x, y ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        if(n<3) cout<< 0 ;
        else
          {
            x=n-1 ;
            y=n-2 ;
            x=x%mod ;
            y=y%mod ;
            n=x*y ;
            n=n/2 ;
            cout<< n%mod << endl ;
          }
      }
  }
