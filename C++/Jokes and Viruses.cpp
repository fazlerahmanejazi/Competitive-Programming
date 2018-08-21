#include <bits/stdc++.h>
using namespace std ;

int main()
{ long long int X, Y, A, B, N, i ;
  cin>> X >> Y ;
  cin>> A >> B ;
  cin>> N ;
  long int a[100010]={0} ;
  a[1]=X ;
  a[2]=Y ;
  for(i=1 ; i<=N-1 ; i++)
  {
    a[i+1]= a[i+1] + a[i]*A ;

    a[i+2]= a[i+2] + a[i]*B ;
  }

  cout<< a[N]%1000000007 ;
  return 0 ;
}
