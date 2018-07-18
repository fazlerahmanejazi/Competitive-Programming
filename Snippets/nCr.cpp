#define mod 1000000007

lli fact[400005] ;

void init()
  {
    fact[0]=1 ;
    for(int i=1 ; i<=400000 ; i++) fact[i]=fact[i-1]*i%mod ;
  }

lli fast_exp(lli base, lli exp)
  {
    lli res=1 ;
    while(exp>0)
      {
        if(exp%2) res=(res*base)%mod ;
        base=(base*base)%mod ;
        exp/=2;
      }
    return res%mod ;
  }

lli getInverse(lli n)
  {
    return fast_exp(n, mod-2) ;
  }

lli divide(lli a, lli b)
  {
    a=a%mod ;
    b=b%mod ;
    return (a*(getInverse(b)%mod))%mod ;
  }

lli nCr(lli n, lli r)
  {
    if(r>n || r<0) return 0 ;
    return divide(divide(fact[n],fact[r]), fact[n-r])%mod ;
  }
