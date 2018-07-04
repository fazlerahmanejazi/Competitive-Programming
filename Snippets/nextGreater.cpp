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
