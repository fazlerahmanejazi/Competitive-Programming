lli root(lli x)
  {
    lli l=0, r=1e9+1, m ;
    while(l<r-1)
      {
        m=(l+r)/2 ;
        if(m*m>x) r=m ;
        else l=m ;
      }
      return l ;
  }
