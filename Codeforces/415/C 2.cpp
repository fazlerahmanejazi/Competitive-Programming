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

/*  long long int fast_exp(int base, int exp) {
    long long int res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}*/

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n ;
    long long int x, y, ans ;
    cin>> n ;
    vector<long long int> a(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    sort(a.begin(), a.end()) ;
    ans=0 ;
    for(int i=0 ; i<n ; i++)
      {
        x=(a[n-i-1]-a[i]+mod)%mod ;
        y=fast_exp(2, n-i-1) ;
        y=y%mod ;
        ans+=x*y ;
        ans=ans%mod ;
      }
    cout<< ans ;
    return 0 ;
  }
