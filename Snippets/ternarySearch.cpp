lli ternary_search(lli lo, lli hi)
  {
    while(lo<hi-2)
      {
      	lli m1=(lo*2+hi)/3 ;
      	lli m2=(lo+hi*2)/3 ;
      	if(check(m1)<check(m2)) hi=m2 ;
      	else lo=m1 ;
      }
    lli ans=check(lo) ;
    for(int i=lo+1 ; i<=hi ; i++) ans=min(ans, check(i)) ;
    return ans ;
  }
