lli phi[1000005] ;

void computeTotient()
  {
    for(lli i=1 ; i<=1000000 ; i++) phi[i]=i ;
    for(lli p=2 ; p<=1000000 ; p++)
      if(phi[p]==p)
        {
          phi[p]=p-1 ;
          for(int i=2*p ; i<=1000000 ; i+=p) phi[i]-=phi[i]/p ;
        }
  }

long long int phi(long long int n)
  {
    long long int res=n ;
    for(long long int p=2 ; p*p<=n ; p++)
      if(!(n%p))
        {
          while(!(n%p)) n/=p ;
          res-=res/p ;
        }
    if(n>1) res-=res/n ;
    return res ;
  }
