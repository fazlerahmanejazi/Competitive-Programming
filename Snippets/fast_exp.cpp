lli fast_exp(lli base, lli exp)
  {
    lli res=1 ;
    base=base%mod ;
    while(exp>0)
      {
        if(exp%2) res=(res*base)%mod ;
        base=(base*base)%mod ;
        exp/=2;
      }
    return res%mod ;
  }

long double ipow(long double x, int d)
  {
    long double ret=1, piv=x ;
    while(d)
      {
        if(d&1) ret=ret*piv ;
        piv=piv*piv ;
        d>>=1 ;
      }
    return ret ;
  }
