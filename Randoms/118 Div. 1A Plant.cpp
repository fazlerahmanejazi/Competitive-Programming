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
    long long int n, ans, x, y ;
    cin>> n ;
    if(n==0)
      {
        cout<< 1 ;
        return 0 ;
      }
    x=fast_exp(2, n-1) ;
    y=fast_exp(2, n) ;
    x=x%mod ;
    y=(y+1)%mod ;
    ans=(x*y)%mod ;
    cout<< ans ;
  }
