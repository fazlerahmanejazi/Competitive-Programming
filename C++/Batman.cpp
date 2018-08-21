#include <bits/stdc++.h>
using namespace std ;

int main()
{
  int T ;
  long int N ;
  long long L, max, temp ;
  cin>> T ;
  while(T--)
  {
    cin>> N >> L ;
    cin>> temp ;
    max=temp ;
    N=N-1 ;
    while(N--)
    {
      cin>> temp ;
      if(temp>max) max=temp ;
    }
    cout<< L-max << endl ;
  }
  return 0 ;
}
