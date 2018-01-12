#include <iostream>
using namespace std;


int main()
{ int n, m,q=0, t=0;
  cin>> n >> m ;
  long int a,b=1;
  while(q!=m)
  {
    cin>> a ;
    if(a>b)
    {
      t=t+(b-a) ;
      b=a ;
    }
    if(a<b)
    {
     t=t+n+a-b ;
    }
    q++ ;
  }
  return 0 ;
}
  