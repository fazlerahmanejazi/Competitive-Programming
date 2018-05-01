
vb isprime ;
vi prime ;

void seive()
  {
    isprime.assign(3000+1, true) ;
    for(int i=2 ; i*i<=3000 ; i++)
      if(isprime[i])
        for(int j=i*i ; j<=3000 ; j+=i)
          isprime[j]=false ;
    prime.pb(2) ;
    for(int i=3 ; i<=3000 ; i+=2) if(isprime[i]) prime.pb(i) ;
  }
