#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n, c=0 ;
    long long int k, x ;
    vector<long long int> seq ;
    cin>> n >> k ;
    vector<bool> check(pow(2,n)+1, true) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        seq.push_back(x) ;
      }
    for(long long int mask=1 ; mask<pow(2,n) ; mask++)
      {
        if(check[mask])
          {
            x=1 ;
            for(int i=0 ; i<n ; i++)
              if(mask&(1<<i))
                {
                  x*=seq[n-i-1] ;
                  if(x>k)
                    {
                      int temp=1<<i ;
                      for(long long j=mask ; j<pow(2,n) ; j++)
                        if((mask&j)==mask) check[j]=false ;
                      break ;
                    }
                }
            if(x<=k) c++ ;
            check[mask]=false ;
          }
      }
    cout<< c ;
  }
