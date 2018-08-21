#include <bits/stdc++.h>
using namespace std ;

int main()
{ int T, type ;
  cin>> T ;

  long N, Q, K, L, R, i, max, ans  ;
  while(T--)
  { max=1 ;
    long a[10010]={0} ;
    cin>> N >> Q ;

    while(Q-- && cin>>type)
    {
      if(type==1)
      {
        cin>> L >> R >> K ;
        if(R>max) max=R ;
        for(i=L ; i<=R ; i++)
        {
          a[i]=a[i]+ K ;
        }
      }
      else
      {
        cin>> L >> R ;
        if(R>max) max=R ;
        for(i=L ; i<=R ; i++)
        {
          a[i]=0 ;
        }
        ans=0 ;
        for(i=1 ; i<=max ; i++)
        {
          ans=ans+a[i] ;
        }
        ans=ans%1000000007 ;
        cout<< ans << endl ;
      }

    }
  }
  return 0 ;
}
