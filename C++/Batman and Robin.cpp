#include <bits/stdc++.h>
using namespace std ;

int main()
{
  int T, d ;
  long int N, M, pos, sum ;
  cin>> T ;
  while(T--)
  { d=1 ; pos=1 ; sum=0 ;
    cin>> N>> M ;
    while(N>0)
    {
      if(d==1)
      {
        sum=sum + (M*(2*pos+ (M-1)))/2 ;
        pos=pos + M ;
        d=-1 ;
        N=N-M ;
      }
      else
      {
        sum=sum + (M*(2*pos+ (M-1)))/2 ;
        pos=pos + M ;
        d=1 ;
        N=N-M ;
      }
    }
    cout<< abs(sum)<< endl ;
  }
  return 0 ;
}
