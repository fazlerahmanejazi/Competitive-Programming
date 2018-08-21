
lli get(lli l, lli r)
  {
    lli m, res=0 ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        if(check(m)) l=m+1, res=max(res, m) ;
        else r=m-1 ;
      }
    return res ;
  }



void nextGreater()
  {
    stack<lli> S ;
    for (int i=n ; i>=0 ; i--)
      {
        while(!S.empty() && a[S.top()]<=a[i]) S.pop() ;
        if(!S.empty()) nge[i]=S.top() ;
        else nge[i]=i ;
        S.push(i) ;
      }
  }
